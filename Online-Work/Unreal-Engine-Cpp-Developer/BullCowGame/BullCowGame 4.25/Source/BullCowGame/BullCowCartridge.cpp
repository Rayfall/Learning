// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    const FString WordListPath = FPaths::ProjectContentDir() / TEXT("WordLists/HiddenWordList.txt");
    FFileHelper::LoadFileToStringArray(Words, *WordListPath);   
    Isograms = CheckWords(Words);
    
    SetupGame(); 
    //GameChecks();    
}

void UBullCowCartridge::GameChecks() {
    //PrintLine(TEXT("The hidden word is: %s, of length: %i"), *HiddenWord, HiddenWord.Len()); // Debug Line    
    //PrintLine(TEXT("Number of possible words is: %i"), Words.Num());
    //for(int32 i = 0; i < 5; i++){PrintLine(TEXT("%s"), *Words[i]);}
    //PrintLine(TEXT("The number of valid words is: %i"), CheckWords(Words).Num());
    //PrintLine(TEXT("%i"), FMath::RandRange(0, 10));
}

TArray<FString> UBullCowCartridge::CheckWords(const TArray<FString>& WordList) const {
    TArray<FString> ValidWords;

    for(FString Word : WordList){
        if(Word.Len() >= 4 && Word.Len() <= 8){
            if(IsIsogram(Word)){
                ValidWords.Emplace(Word);
            }            
        }        
    }
    return ValidWords;
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
    HiddenWord = Isograms[FMath::RandRange(0,Isograms.Num() - 1)];
    PlayerGuesses = HiddenWord.Len();
    bGameOver = false;

    PrintLine(TEXT("Welcome to Bull & Cows!\nTry guessing the %i Letter word!"), HiddenWord.Len());
    PrintLine(TEXT("You have %i guesses to start off with. Every wrong guess will subtract the number of guesses."), PlayerGuesses);
    PrintLine(TEXT("Type in your guess now and continue by pressing enter!"));
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Continue by pressing enter!")); 
}

void UBullCowCartridge::ProcessGuess(const FString& Guess)
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
            FBullCowCount Score = GetBullCows(Guess);
            PrintLine(TEXT("You have %i Bulls and %i Cows."), Score.Bulls, Score.Cows);
            PrintLine(TEXT("Guesses Remaining: %i"), PlayerGuesses);
            PrintLine(TEXT("Try Again."));
        }else{
            PrintLine(TEXT("You have lost."));
            EndGame();
        }      
    }
     
}

bool UBullCowCartridge::IsIsogram(const FString& Word) const
{
    for(int32 Index = 0; Index < Word.Len(); Index++){
        for(int32 Comparison = Index + 1; Comparison < Word.Len(); Comparison++){
            if(Word[Index] == Word[Comparison]){
                return false;
            }        
        }
    }    
    return true;
}

FBullCowCount UBullCowCartridge::GetBullCows(const FString& Guess) const
{
    FBullCowCount Count;

    for (int32 GuessIndex = 0; GuessIndex < Guess.Len(); GuessIndex++){
        if(Guess[GuessIndex] == HiddenWord[GuessIndex]){
            Count.Bulls ++;
            continue;
        }

        for(int32 HiddenIndex = 0; HiddenIndex < HiddenWord.Len(); HiddenIndex++){
            if(Guess[GuessIndex] == HiddenWord[HiddenIndex]){
                Count.Cows ++;
                break;
            }
        }
    }

    return Count;
}