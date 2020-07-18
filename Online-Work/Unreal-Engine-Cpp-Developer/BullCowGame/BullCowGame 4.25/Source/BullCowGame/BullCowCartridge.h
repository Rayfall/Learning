// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Console/Cartridge.h"
#include "BullCowCartridge.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BULLCOWGAME_API UBullCowCartridge : public UCartridge
{
	GENERATED_BODY()

	public:
	virtual void BeginPlay() override;
	virtual void OnInput(const FString& Input) override;
	TArray<FString> CheckWords(TArray<FString>) const;
	void EndGame();
	void GameChecks();
	void ProcessGuess(FString Guess);	
	void SetupGame();

	bool IsIsogram(FString Word) const;

	// Your declarations go below!
	private:
		FString HiddenWord;
		int32 PlayerGuesses;
		bool bGameOver;
		TArray<FString> Words;
	
};
