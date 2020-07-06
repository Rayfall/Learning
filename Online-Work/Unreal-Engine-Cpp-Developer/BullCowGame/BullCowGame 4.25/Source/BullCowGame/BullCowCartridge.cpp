// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame(); 

    //PrintLine(TEXT("The hidden word is: %s, of length: %i"), *HiddenWord, HiddenWord.Len()); // Debug Line    
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
    
    if(HiddenWord == Input){
        PrintLine(TEXT("Correct!"));
        EndGame();
    }else{
        if(HiddenWord.Len() != Input.Len()){
            PrintLine(TEXT("Hidden word is %i Characters long, this does not match."), HiddenWord.Len());
        }

        if(PlayerGuesses > 0){
            PlayerGuesses = PlayerGuesses - 1;
            PrintLine(TEXT("%i"), PlayerGuesses);
            PrintLine(TEXT("Try Again."));
        }else{
            PrintLine(TEXT("You have lost."));
            EndGame();
        }
        
        
    }
}

void UBullCowCartridge::SetupGame()
{
    HiddenWord = TEXT("boil");
    PlayerGuesses = 5;
    bGameOver = false;

    PrintLine(TEXT("Welcome to Bull & Cows!\nTry guessing the %i Letter word!"), HiddenWord.Len());
    PrintLine(TEXT("You have %i guesses to start off with. Every wrong guess will subtract the number of guesses."), PlayerGuesses);
    PrintLine(TEXT("Type in your guess now and continue by pressing enter!"));
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    
}