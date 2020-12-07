// Fill out your copyright notice in the Description page of Project Settings.


#include "TankGameModeBass.h"


void ATankGameModeBass::BeginPlay()
{
    // Get references and game win/lose conditions.

    // Call HandleGameStart() to initialize the start countdown, turrect activation, pawn check etc.
}

void ATankGameModeBass::HandleGameStart()
{
    // Initialize the start countdown, turret activation, etc.
    // Call Blueprint version GameStart()
}

void ATankGameModeBass::HandleGameOver(bool PlayerWon)
{
    // See if the player has destroyed all the turrets, show win result.
    // else if turret destroyed player, show lose result.
    // Call blueprint version GameOver(bool)
}

void ATankGameModeBass::ActorDied(AActor* DeadActor)
{
    // Check what type of Actor died. If turret, tally. If Player-> go to lose condition.
    UE_LOG(LogTemp, Warning, TEXT("A Pawn has fallen"));
}