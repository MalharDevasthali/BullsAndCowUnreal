// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    SetupGame();
}

void UBullCowCartridge::OnInput(const FString &Input) // When the player hits enter
{
    ClearScreen();
    if (bGameOver)
    {
        ReplayGame();
    }
    else
    {
        ProcessGuess(Input);
    }
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    if (hiddenIsogram == Guess)
    {
        GameOver(true);
    }
    else
    {
        ReduceLife(Guess);
    }
}

void UBullCowCartridge::ReduceLife(FString Guess)
{
  
    lives--;
    int32 hiddenIsoLength = hiddenIsogram.Len();



    if (lives <= 0)
    {
        GameOver(false);
        return;
    }

    PrintLine(TEXT("You Lost one life.\nYou have %i lives left"), lives);
  
    if (Guess.Len() != hiddenIsogram.Len())
    {
        PrintLine(TEXT("Hidden word is of %i length\nPlease enter %i length word"), hiddenIsoLength, hiddenIsoLength);

        return;
    }

    if (!IsIsogram(Guess))
    {
        PrintLine(TEXT("Its not Isogram please try again"));
        return;
    }
}

bool UBullCowCartridge::IsIsogram(FString typedWord)
{
    INT16 asciiArray[255];
    for (int i = 0; i < 255; i++)
    {
        asciiArray[i] = 0;
    }

    for (int i = 0; i < typedWord.Len(); i++)
    {
        asciiArray[typedWord[i]]++;
        
    }
    for (int i = 0; i < 255; i++)
    {
        if (asciiArray[i] > 1)
        {
            return false;
        }
    }

    return true;

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

void UBullCowCartridge::ReplayGame()
{
    SetupGame();
}

void UBullCowCartridge::GameOver(bool hasWon)
{
    bGameOver = true;
    if (hasWon)
        PrintLine(TEXT("Great You Won!\nPress Enter to Continue,Esc to Quit!"));
    else
        PrintLine(TEXT("You Lost!\nPress Enter to Continue, Esc to Quit!"));
    
}
