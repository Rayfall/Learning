// Fill out your copyright notice in the Description page of Project Settings.

#include "Door_Open.h"
#include "Components/AudioComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"


// Sets default values for this component's properties
UDoor_Open::UDoor_Open()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UDoor_Open::BeginPlay()
{
	Super::BeginPlay();

	InitialYaw = GetOwner()->GetActorRotation().Yaw;
	CurrentYaw = InitialYaw;
	OpenAngle += InitialYaw;

	FindPressurePlate();
	FindAudioComponent();
	// ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
}

// Called every frame
void UDoor_Open::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(TotalMassOfActors() > MassToOpenDoors) {
		OpenDoor(DeltaTime);
		DoorLastOpened = GetWorld()->GetTimeSeconds();
	} else {
		if((GetWorld()->GetTimeSeconds() - DoorLastOpened) > DoorCloseDelay) {
			CloseDoor(DeltaTime);
		}		
	}
}

void UDoor_Open::OpenDoor(float DeltaTime) {
	CurrentYaw = FMath::FInterpTo(CurrentYaw, OpenAngle, DeltaTime, DoorOpenSpeed);
	FRotator DoorRotation = GetOwner()->GetActorRotation();
	DoorRotation.Yaw = CurrentYaw;
	GetOwner()->SetActorRotation(DoorRotation);

	CloseDoorSound = false;
	if(!AudioComponent){return;}
	if(!OpenDoorSound){
		AudioComponent->Play();
		OpenDoorSound = true;
	}
}

void UDoor_Open::CloseDoor(float DeltaTime) {
	CurrentYaw = FMath::FInterpTo(CurrentYaw, InitialYaw, DeltaTime, DoorCloseSpeed);
	FRotator DoorRotation = GetOwner()->GetActorRotation();
	DoorRotation.Yaw = CurrentYaw;
	GetOwner()->SetActorRotation(DoorRotation);

	OpenDoorSound = false;
	if(!AudioComponent){return;}
	if(!CloseDoorSound){
		AudioComponent->Play();
		CloseDoorSound = true;
	}	
}

float UDoor_Open::TotalMassOfActors() const{
	float TotalMass = 0.f;

	TArray<AActor*> OverlappingActors;
	if(!PressurePlate){return TotalMass;}
	PressurePlate->GetOverlappingActors(OUT OverlappingActors);

	for(AActor* Actor : OverlappingActors){
		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
	}
	return TotalMass;
}

void UDoor_Open::FindPressurePlate(){
	if(!PressurePlate) {
		UE_LOG(LogTemp, Error, TEXT("%s has the open door component on it, but no PressurePlate set."), *GetOwner()->GetName());
	}
}
void UDoor_Open::FindAudioComponent() {
	AudioComponent = GetOwner()->FindComponentByClass<UAudioComponent>();
	if(!AudioComponent){
		UE_LOG(LogTemp, Error, TEXT("%s Missing Audio Component"), *GetOwner()->GetName());
	}
}

/*
Extra Code
	// Taken from BeginPlay()
	// UE_LOG(LogTemp, Warning, TEXT("%s"), *GetOwner()->GetActorRotation().ToString());
	// UE_LOG(LogTemp, Warning, TEXT("Yaw is: %f"), GetOwner()->GetActorRotation().Yaw);	

	// float CurrentYaw = GetOwner()->GetActorRotation().Yaw;
	// FRotator OpenDoor(0.f, OpenAngle, 0.f);
	// OpenDoor.Yaw = FMath::Lerp(CurrentYaw, OpenAngle, 0.02f); // Base Linear Interpolation
	// OpenDoor.Yaw = FMath::Lerp(CurrentYaw, OpenAngle, DeltaTime * 1.f); // Base Linear Interpolation with Deltatime
	// OpenDoor.Yaw = FMath::FInterpConstantTo(CurrentYaw, OpenAngle, DeltaTime, 90); // Linear Interpolation
	// OpenDoor.Yaw = FMath::FInterpTo(CurrentYaw, OpenAngle, DeltaTime, 4); // Exponential Interpolation
	// GetOwner()->SetActorRotation(OpenDoor);


	// My attempt - FMath::Lerp(0, 85, 1);


	// Extra code.
	float SimpleFloat = 90.f;

	FRotator CurrentRotation = GetOwner()->GetActorRotation();
	CurrentRotation.Yaw = SimpleFloat;

	FRotator OpenDoor(0.f,90.f,0.f);
	GetOwner()->SetActorRotation(OpenDoor);
*/
