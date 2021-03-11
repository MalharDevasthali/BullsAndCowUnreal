// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Welcome to Bull and Cow Game"));
    PrintLine(TEXT("Press Enter to Continue:"));
    InitGame();
}

void UBullCowCartridge::OnInput(const FString &Input) // When the player hits enter
{
    ClearScreen();
    if (hiddenIsogram == Input)
    {
        PrintLine(TEXT("Great You Won!"));
        GameWon();
    }
    else
    {
        // for (int i = 0; i < Input.)
        PrintLine(TEXT("Lost!"));

        lives--;
        if (lives > 0)
        {
            ContinueNextTry();
        }
        else
        {
            GameLost();
        }
    }
}
void UBullCowCartridge::InitGame()
{
    hiddenIsogram = TEXT("unreal");
    lives = 4;
}
void UBullCowCartridge::ContinueNextTry()
{
}
void UBullCowCartridge::QuitGame()
{
}
void UBullCowCartridge::ReplayGame()
{
}
void UBullCowCartridge::GameLost()
{
}
void UBullCowCartridge::GameWon()
{
}
