// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    
    Difficulty = 3;
    SetupGame(Difficulty);
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{

    if(!bGameOver)
    {
        if(HiddenWord!=Input)
        {
            Lives -= 1;

            if(Lives <= 0)
            {
                PrintLine(TEXT("You are out of lives.\nThe word was: %s"), *HiddenWord);
                EndGame();
                return;
            }

            PrintLine(TEXT("That's not right, but you can do this!\nYou still have %i live(s)."), Lives);

            if(HiddenWord.Len()!=Input.Len())
                PrintLine(TEXT("Please try a %i letters word."), HiddenWord.Len());
            return;
        }
        PrintLine(TEXT("Congratulations!\nThat's a win.\nYou're great on this!"));
        EndGame();
    }
    ClearScreen();
    SetupGame(Difficulty);
}

void UBullCowCartridge::SetupGame(int32 difficulty)
{
    PrintLine(TEXT("Welcome to the game."));

    switch (difficulty)
    {
        case 1: 
        {
            HiddenWord = EasyWords[FMath::RandRange(0, 99)];
            break;
        }
        case 2: 
        {
            HiddenWord = NormalWords[FMath::RandRange(0, 99)];
            break;
        }
        case 3: 
        {
            HiddenWord = HardWords[FMath::RandRange(0, 99)];
            break;
        }
        default: 
        {
            PrintLine(TEXT("Please select a valid difficulty."));
            break;
        }
    }
    
    Lives = 5;
    bGameOver = false;

    PrintLine(TEXT("HiddenWord: %s"), *HiddenWord);
    PrintLine(TEXT("Type your guess for the %i letters word and press ENTER to submit..."), HiddenWord.Len());
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press ENTER to play with another word..."));
}
