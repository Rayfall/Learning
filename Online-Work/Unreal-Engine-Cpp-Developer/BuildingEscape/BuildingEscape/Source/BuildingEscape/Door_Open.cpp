// Fill out your copyright notice in the Description page of Project Settings.


#include "Engine/World.h"
#include "Door_Open.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"

// Sets default values for this component's properties
UDoor_Open::UDoor_Open()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDoor_Open::BeginPlay()
{
	Super::BeginPlay();

	InitialYaw = GetOwner()->GetActorRotation().Yaw;
	CurrentYaw = InitialYaw;
	OpenAngle += InitialYaw;
	//OpenAngle = InitialYaw + 90.f;

	if(!PressurePlate) {
		UE_LOG(LogTemp, Error, TEXT("%s has the open door component on it, but no PressurePlate set."), *GetOwner()->GetName());
	}

	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
}


// Called every frame
void UDoor_Open::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(PressurePlate && PressurePlate->IsOverlappingActor(ActorThatOpens)) {
		OpenDoor(DeltaTime);
		DoorLastOpened = GetWorld()->GetTimeSeconds();
	} else {
		if((GetWorld()->GetTimeSeconds() - DoorLastOpened) > DoorCloseDelay) {
			CloseDoor(DeltaTime);
		}		
	}

	
	

	// UE_LOG(LogTemp, Warning, TEXT("%s"), *GetOwner()->GetActorRotation().ToString());
	// UE_LOG(LogTemp, Warning, TEXT("Yaw is: %f"), GetOwner()->GetActorRotation().Yaw);	

	// float CurrentYaw = GetOwner()->GetActorRotation().Yaw;
	// FRotator OpenDoor(0.f, OpenAngle, 0.f);
	// OpenDoor.Yaw = FMath::Lerp(CurrentYaw, OpenAngle, 0.02f); // Base Linear Interpolation
	// OpenDoor.Yaw = FMath::Lerp(CurrentYaw, OpenAngle, DeltaTime * 1.f); // Base Linear Interpolation with Deltatime
	// OpenDoor.Yaw = FMath::FInterpConstantTo(CurrentYaw, OpenAngle, DeltaTime, 90); // Linear Interpolation
	// OpenDoor.Yaw = FMath::FInterpTo(CurrentYaw, OpenAngle, DeltaTime, 4); // Exponential Interpolation
	// GetOwner()->SetActorRotation(OpenDoor);


	// My attempt - FMath::Lerp(/*0, 85, 1*/);


	// Extra code.
	/*float SimpleFloat = 90.f;

	FRotator CurrentRotation = GetOwner()->GetActorRotation();
	CurrentRotation.Yaw = SimpleFloat;

	FRotator OpenDoor(0.f,90.f,0.f);
	GetOwner()->SetActorRotation(OpenDoor);*/
}

void UDoor_Open::OpenDoor(float DeltaTime) {
	CurrentYaw = FMath::FInterpTo(CurrentYaw, OpenAngle, DeltaTime, DoorOpenSpeed);
	FRotator DoorRotation = GetOwner()->GetActorRotation();
	DoorRotation.Yaw = CurrentYaw;
	GetOwner()->SetActorRotation(DoorRotation);
}

void UDoor_Open::CloseDoor(float DeltaTime) {
	CurrentYaw = FMath::FInterpTo(CurrentYaw, InitialYaw, DeltaTime, DoorCloseSpeed);
	FRotator DoorRotation = GetOwner()->GetActorRotation();
	DoorRotation.Yaw = CurrentYaw;
	GetOwner()->SetActorRotation(DoorRotation);
}
