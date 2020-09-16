// Fill out your copyright notice in the Description page of Project Settings.

#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
//#include "CollisionQueryParams.h"
//#include "UObject/NameTypes.h"
#include "Grabber.h"

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Grabber Reporting for duty!"));

	// Check for Physics Handle Component
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if(PhysicsHandle){
		UE_LOG(LogTemp, Display, TEXT("Physics handle found: %s"), *GetOwner()->GetName());
	}
	else{
		UE_LOG(LogTemp, Error, TEXT("No Physics handle found on component: %s"), *GetOwner()->GetName());
	}

	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if(InputComponent){
		UE_LOG(LogTemp, Display, TEXT("Input component found: %s"), *GetOwner()->GetName());
		InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
	}
	else{
		UE_LOG(LogTemp, Error, TEXT("No Input component found on component: %s"), *GetOwner()->GetName());
	}
}

void UGrabber::Grab(){
	UE_LOG(LogTemp, Display, TEXT("Grabber pressed"));
}

// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Get players view point
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
	);

	// UE_LOG(LogTemp, Warning, TEXT("Location: %s"), *PlayerViewPointLocation.ToString());
	// UE_LOG(LogTemp, Warning, TEXT("Rotation: %s"), *PlayerViewPointRotation.ToString());

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
	
}

