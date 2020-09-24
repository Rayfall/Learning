// Fill out your copyright notice in the Description page of Project Settings.
#include "Grabber.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"


#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	FindPhysicsHandle();	
	InputSetup();
}

void UGrabber::FindPhysicsHandle(){
	// Check for Physics Handle Component
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if(PhysicsHandle){
		UE_LOG(LogTemp, Display, TEXT("Physics handle found: %s"), *GetOwner()->GetName());
	}
	else{
		UE_LOG(LogTemp, Error, TEXT("No Physics handle found on component: %s"), *GetOwner()->GetName());
	}
}

void UGrabber::InputSetup(){
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();

	if(InputComponent){
		InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
		InputComponent->BindAction("Grab", IE_Released, this, &UGrabber::Release);
	}
}

void UGrabber::Grab(){

	// Get players view point
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
	);

	FVector LineTraceEnd = PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;


	UE_LOG(LogTemp, Display, TEXT("Grabber pressed"));
	// TODO, only raycast when key is pressed and when in reach
	FHitResult HitResult = GetFirstPhysicsBodyInReach();
	UPrimitiveComponent* ComponentToGrab = HitResult.GetComponent();

	// Try and reach any actors with physics body collision channel set.

	// If we hit something, then attach the physics handle.
	// TODO attach physics handle.
	if(HitResult.GetActor()){
		PhysicsHandle->GrabComponentAtLocation(
			ComponentToGrab,
			NAME_None,
			LineTraceEnd
		);
	}
}

void UGrabber::Release(){
	UE_LOG(LogTemp, Display, TEXT("Grabber released"));
	PhysicsHandle->ReleaseComponent();
}

FHitResult UGrabber::GetFirstPhysicsBodyInReach() const{
	// Get players view point
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
	);

	FVector LineTraceEnd = PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;

	// Ray-cast out to a certain distance (Reach)
	FHitResult Hit;
	FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());

	GetWorld()->LineTraceSingleByObjectType(
		OUT Hit,
		PlayerViewPointLocation,
		LineTraceEnd,
		FCollisionObjectQueryParams(
			ECollisionChannel::ECC_PhysicsBody
		),
		TraceParams
	);

	// See what we are hitting
	AActor* ActorHit = Hit.GetActor();

	if(ActorHit){
		UE_LOG(LogTemp, Warning, TEXT("Line trace has hit: %s"), *(ActorHit->GetName()));
	}

	return Hit;
}

// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
	);

	FVector LineTraceEnd = PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;

	if(PhysicsHandle->GrabbedComponent){
		PhysicsHandle->SetTargetLocation(LineTraceEnd);
	}
}

/* All commented code for reference{
	//Logging Viewpoint location From TickComponent()
	UE_LOG(LogTemp, Warning, TEXT("Location: %s"), *PlayerViewPointLocation.ToString());
	UE_LOG(LogTemp, Warning, TEXT("Rotation: %s"), *PlayerViewPointRotation.ToString());

	//Creating a line of site in unreal from TickComponent()
	FVector LineTraceEnd = PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;

	DrawDebugLine(
		GetWorld(),
		PlayerViewPointLocation,
		LineTraceEnd,
		FColor(0,0,255),
		false,
		0.f,
		0,
		5
	);
}*/