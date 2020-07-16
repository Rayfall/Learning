// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame(); 

    PrintLine(TEXT("The hidden word is: %s, of length: %i"), *HiddenWord, HiddenWord.Len()); // Debug Line    
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    if(bGameOver == true){
        ClearScreen();
        SetupGame();
    }else{
        ProcessGuess(Input);
    }   
}

void UBullCowCartridge::SetupGame()
{
    HiddenWord = TEXT("boil");
    PlayerGuesses = HiddenWord.Len();
    bGameOver = false;

    PrintLine(TEXT("Welcome to Bull & Cows!\nTry guessing the %i Letter word!"), HiddenWord.Len());
    PrintLine(TEXT("You have %i guesses to start off with. Every wrong guess will subtract the number of guesses."), PlayerGuesses);
    PrintLine(TEXT("Type in your guess now and continue by pressing enter!"));

    const TCHAR HW[] = TEXT("boil");
    /*const TCHAR HW[] = {
        TEXT('b'),
        TEXT('o'),
        TEXT('i'),
        TEXT('l')
    };*/
    PrintLine(TEXT("Character 1 of the hidden word is: %c"), HiddenWord[0]);
    PrintLine(TEXT("The last letter of the hidden word is: %c"), HW[3]);
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Continue by pressing enter!")); 
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    if(HiddenWord == Guess){
            PrintLine(TEXT("Correct!"));
            EndGame();
        }else{
             if(HiddenWord.Len() != Guess.Len()){
        PrintLine(TEXT("Hidden word is %i Characters long, this does not match."), HiddenWord.Len());
    }

    if(!IsIsogram(Guess)){
        PrintLine(TEXT("No repeating letters, guess again."));
        return;
    }

    if(PlayerGuesses > 1){
        PlayerGuesses = --PlayerGuesses;
        PrintLine(TEXT("Guesses Remaining: %i"), PlayerGuesses);
        PrintLine(TEXT("Try Again."));
    }else{
        PrintLine(TEXT("You have lost."));
        EndGame();
    }      
        }
     
}

bool UBullCowCartridge::IsIsogram(FString Word) 
{
    return true;
}