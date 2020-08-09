// Fill out your copyright notice in the Description page of Project Settings.


#include "Door_Open.h"
#include "GameFramework/Actor.h"

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

	float SimpleFloat = 90.f;

	FRotator CurrentRotation = GetOwner()->GetActorRotation();
	//CurrentRotation.
	
}


// Called every frame
void UDoor_Open::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

