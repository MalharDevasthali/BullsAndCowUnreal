// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Console/Cartridge.h"
#include "BullCowCartridge.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BULLCOWGAME_API UBullCowCartridge : public UCartridge
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void OnInput(const FString &Input) override;
	void InitGame();
	void ContinueNextTry();
	void ReplayGame();
	void GameLost();
	void GameWon();
	void QuitGame();

	// Your declarations go below!
private:
	FString hiddenIsogram; //Isogram is a string where no words will appear more than once in a string
	int32 lives;
};
