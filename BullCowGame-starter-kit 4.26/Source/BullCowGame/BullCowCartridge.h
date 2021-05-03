// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Console/Cartridge.h"
#include "BullCowCartridge.generated.h"


struct BullsCowsCount
{
	//by default these variables will be public 
	int32 Bulls = 0;
	int32 Cows = 0;
};


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BULLCOWGAME_API UBullCowCartridge : public UCartridge
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void OnInput(const FString &Input) override;
	void SetupGame();
	void ReplayGame();
	void GameOver(bool);
	void ProcessGuess(const FString &Guess);
	void ReduceLife(const FString &Guess);
	bool IsIsogram(const FString &word) const; //Example of const function which will not modify any memeber variables of the class
	void CalculateBullsAndCows(const FString &typedWordLength);
	

	// Your declarations go below!
private:
	FString hiddenIsogram; //Isogram is a string where no words will appear more than once in a string
	int32 lives;
	bool bGameOver;

};
