// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldSphere.h"
#include "GameFramework/Actor.h"

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
	// Learning about different ways to display information to the console.
	/* UE_LOG(LogTemp, Display, TEXT("This is the Display Log."));
	// UE_LOG(LogTemp, Warning, TEXT("This is the Warning Log."));
	// UE_LOG(LogTemp, Error, TEXT("This is the Error Log."));
	*/

	// Learning about the use of pointers in Unreal.
	/*FString Log = TEXT("Hello!");
	FString* PtrLog = &Log;

	(*PtrLog).Len(); // This is the same as Log.Len()
	PtrLog->Len(); // Also the same.

	UE_LOG(LogTemp, Warning, TEXT("%s"), *Log);
	UE_LOG(LogTemp, Warning, TEXT("%s"), **PtrLog);*/

	// Challenge
	FString ObjectName = GetOwner()->GetName();
	UE_LOG(LogTemp, Warning, TEXT("Object name: %s"), *ObjectName);
	FString ObjectPosition = GetOwner()->GetActorLocation().ToString();
	UE_LOG(LogTemp, Warning, TEXT("Object position in world: %s"), *ObjectPosition);
	// Other Version
	// UE_LOG(LogTemp, Warning, TEXT("Object name: %s"), *GetOwner()->GetName());
}


// Called every frame
void UWorldSphere::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

