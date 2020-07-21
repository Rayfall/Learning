// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldSphere.h"

// Sets default values for this component's properties
UWorldSphere::UWorldSphere()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWorldSphere::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Display, TEXT("This is the Display Log."));
	UE_LOG(LogTemp, Warning, TEXT("This is the Warning Log."));
	UE_LOG(LogTemp, Error, TEXT("This is the Error Log."));
	// ...
	
}


// Called every frame
void UWorldSphere::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

