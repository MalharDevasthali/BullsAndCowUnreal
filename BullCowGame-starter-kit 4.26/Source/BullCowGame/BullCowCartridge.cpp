// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    SetupGame();



    //Hi()
}

void UBullCowCartridge::OnInput(const FString &Input) // When the player hits enter
{

    if (bGameOver)
    {
        ReplayGame();
    }
    else
    {

        if (hiddenIsogram == Input)
        {
            PrintLine(TEXT("Great You Won!\nPress Enter to Continue"));
            GameOver();
        }
        else
        {

            int32 hiddenIsoLength = hiddenIsogram.Len();

            if (Input.Len() != hiddenIsogram.Len())
            {
                PrintLine(TEXT("Hidden word is of %i length, please enter %i length word"), hiddenIsoLength, hiddenIsoLength);
            }

            lives--;
            if (lives > 0)
            {
                ContinueNextTry();
            }
            else
            {
                PrintLine(TEXT("You Lost!\nPress Enter to Continue"));
                GameOver();
            }
        }
    }
}

void UBullCowCartridge::SetupGame()
{
    hiddenIsogram = TEXT("unreal");
    lives = hiddenIsogram.Len();
    bGameOver = false;

    PrintLine(TEXT("Hidden word is %s.\nThe length of the word is %i"), *hiddenIsogram, hiddenIsogram.Len());
    PrintLine(TEXT("Welcome to Bull and Cow Game"));
    PrintLine(TEXT("Guess a %i letter word"), hiddenIsogram.Len());
    PrintLine(TEXT("Enter your guess"));
}
void UBullCowCartridge::ContinueNextTry()
{
    PrintLine(TEXT("You Lost one life.\nYou have %i lives left"), lives);
}
void UBullCowCartridge::ReplayGame()
{
    ClearScreen();
    SetupGame();
    PrintLine("Press Enter to Play Again , Esc to Quit!");
}

void UBullCowCartridge::GameOver()
{
    bGameOver = true;
}
