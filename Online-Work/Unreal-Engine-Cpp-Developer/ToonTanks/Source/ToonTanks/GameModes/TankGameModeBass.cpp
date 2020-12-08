// Fill out your copyright notice in the Description page of Project Settings.


#include "TankGameModeBass.h"
#include "ToonTanks/Pawns/PawnTank.h"
#include "ToonTanks/Pawns/PawnTurret.h"
#include "Kismet/GameplayStatics.h"


void ATankGameModeBass::BeginPlay()
{
    Super::BeginPlay();
    // Get references and game win/lose conditions.

    // Call HandleGameStart() to initialize the start countdown, turrect activation, pawn check etc.
    HandleGameStart();
}

void ATankGameModeBass::HandleGameStart()
{
    // Initialize the start countdown, turret activation, etc.
    TargetTurrets = GetTargetTurretCount();

    PlayerTank = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
    // Call Blueprint version GameStart()
    GameStart();
}

void ATankGameModeBass::HandleGameOver(bool PlayerWon)
{
    // See if the player has destroyed all the turrets, show win result.
    // else if turret destroyed player, show lose result.
    // Call blueprint version GameOver(bool)
    GameOver(PlayerWon);
}

void ATankGameModeBass::ActorDied(AActor* DeadActor)
{
    // Check what type of Actor died. If turret, tally. If Player-> go to lose condition.
    UE_LOG(LogTemp, Warning, TEXT("A Pawn has fallen"));

    if(DeadActor == PlayerTank){
        PlayerTank->HandleDestruction();
        HandleGameOver(false);
    }else if(APawnTurret* DestroyedTurret = Cast<APawnTurret>(DeadActor)){
        DestroyedTurret->HandleDestruction();
        if(--TargetTurrets == 0){
            HandleGameOver(true);
        }
    }
}

int32 ATankGameModeBass::GetTargetTurretCount()
{
    TArray<AActor*> TurretActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), APawnTurret::StaticClass(), TurretActors);
    return TurretActors.Num();
}