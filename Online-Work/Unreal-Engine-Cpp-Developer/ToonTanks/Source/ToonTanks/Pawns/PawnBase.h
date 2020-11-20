<<<<<<< HEAD
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnBase.generated.h"

class UCapsuleComponent;

UCLASS()
class TOONTANKS_API APawnBase : public APawn
{
	GENERATED_BODY()

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UCapsuleComponent* CapsuleComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))	
	UStaticMeshComponent* BaseMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))	
	USceneComponent* ProjectileSpawnPoint;

public:
	// Sets default values for this pawn's properties
	APawnBase();
	
};

	/*UPROPERTY(VisibleAnywhere, Category = "DEMO")
	int VisibleAnywhere;
	UPROPERTY(VisibleDefaultsOnly, Category = "DEMO")
	int VisibleDefaultsOnly;
	UPROPERTY(VisibleInstanceOnly, Category = "DEMO")
	int VisibleInstanceOnly;
	UPROPERTY(EditAnywhere, Category = "DEMO")
	int EditAnywhere;
	UPROPERTY(EditDefaultsOnly, Category = "DEMO")
	int EditDefaultsOnly;
	UPROPERTY(EditInstanceOnly, Category = "DEMO")
	int EditInstanceOnly;*/