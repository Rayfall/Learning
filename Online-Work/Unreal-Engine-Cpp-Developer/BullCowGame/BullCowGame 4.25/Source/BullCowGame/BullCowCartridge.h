// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Console/Cartridge.h"
#include "BullCowCartridge.generated.h"

struct FBullCowCount 
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BULLCOWGAME_API UBullCowCartridge : public UCartridge
{
	GENERATED_BODY()

	public:
	virtual void BeginPlay() override;
	virtual void OnInput(const FString& Input) override;

	TArray<FString> CheckWords(const TArray<FString>& WordList) const;

	void EndGame();
	void GameChecks();
	FBullCowCount GetBullCows(const FString& Guess) const;
	void ProcessGuess(const FString& Guess);	
	void SetupGame();

	bool IsIsogram(const FString& Word) const;

	// Your declarations go below!
	private:
		FString HiddenWord;
		int32 PlayerGuesses;
		bool bGameOver;
		TArray<FString> Words;
		TArray<FString> Isograms;
};
