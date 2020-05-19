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
        ProcessGuess(Input);
        return;
    }
    ClearScreen();
    SetupGame(Difficulty);
}

void UBullCowCartridge::SetupGame(int32 difficulty)
{
    PrintLine(TEXT("Welcome to the game."));
    bGameOver = false;

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
        case 4: 
        {
            HiddenWord = VeryHardWords[FMath::RandRange(0, 216)];
            break;
        }
        default: 
        {
            PrintLine(TEXT("Please select a valid difficulty."));
            break;
        }
    }
    
    Lives = HiddenWord.Len();

    PrintLine(TEXT("HiddenWord: %s"), *HiddenWord);
    PrintLine(TEXT("Type your guess for the %i letter word and press ENTER to submit..."), HiddenWord.Len());
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press ENTER to play with another word..."));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    if(HiddenWord!=Guess)
    {
        --Lives;

        if(Lives <= 0)
        {
            PrintLine(TEXT("You are out of lives.\nThe word was: %s"), *HiddenWord);
            EndGame();
            return;
        }

        PrintLine(TEXT("That's not right, but you can do this!\nYou still have %i live(s)."), Lives);

        if(HiddenWord.Len()!=Guess.Len())
            PrintLine(TEXT("Please try a %i letter word."), HiddenWord.Len());
        return;
    }
    PrintLine(TEXT("*****Congratulations!*****\nThat's a win.\nYou're great on this!"));
    EndGame();
}
