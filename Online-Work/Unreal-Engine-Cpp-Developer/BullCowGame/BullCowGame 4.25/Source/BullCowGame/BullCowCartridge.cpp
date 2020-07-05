// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();    
    
    PrintLine(TEXT("Welcome to Bull & Cows!\nTry guessing the 4 Letter word!"));
    PrintLine(TEXT("You have 5 to start off with. Every wrong guess will subtract the number of guesses."));

    InitGame();
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();

    if(HiddenWord == Input){
        PrintLine(TEXT("Correct!"));
    }else{
        PrintLine(TEXT("Try Again."));
        PlayerGuesses = PlayerGuesses - 1;
    }
}

void UBullCowCartridge::InitGame()
{
    HiddenWord = TEXT("boil");
    PlayerGuesses = 5;

}