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

void UBullCowCartridge::SetupGame(int32 Difficulty)
{
    PrintLine(TEXT("Welcome to the game."));
    bGameOver = false;

    switch (Difficulty)
    {
        case 1: 
        {
            HiddenWord = EasyWords[FMath::RandRange(0, 159)];
            break;
        }
        case 2: 
        {
            HiddenWord = NormalWords[FMath::RandRange(0, 159)];
            break;
        }
        case 3: 
        {
            HiddenWord = HardWords[FMath::RandRange(0, 159)];
            break;
        }
        case 4: 
        {
            HiddenWord = VeryHardWords[FMath::RandRange(0, 159)];
            break;
        }
        default: 
        {
            PrintLine(TEXT("Please select a valid difficulty."));
            return;
        }
    }
    
    Lives = HiddenWord.Len();

    PrintLine(TEXT("HiddenWord: %s"), *HiddenWord);
    PrintLine(TEXT("Type your guess for the %i letter isogram \nand press ENTER to submit..."), HiddenWord.Len());
}

bool UBullCowCartridge::IsIsogram(FString Word)
{
    // int32 aux = 0;
    // int32 max = 0;
    // int32 min = 999999;

    // for(int32 j=0; j < Word.Len(); j++)
    // {   
    //     aux = 0;
    //     for(int32 i=0; i < Word.Len(); i++)
    //     {
    //         if(Word[j] == Word[i])
    //             aux++;
    //     }
    //     if(aux > max)
    //         max = aux;
    //     if(aux < min)
    //         min = aux;
    // }

    // if(min != max)
    // {
    //     PrintLine("Returning false");
    //     return false;
    // }

    // PrintLine(TEXT("Returning true"));
    // return true;
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    if(HiddenWord.Len() > 0)
    {
        if(HiddenWord!=Guess)
        {
            --Lives;

            if(Lives <= 0)
            {
                PrintLine(TEXT("You are out of lives.\nThe isogram was: %s"), *HiddenWord);
                EndGame();
                return;
            }

            PrintLine(TEXT("That's not right, but you can do this!\nYou still have %i live(s)."), Lives);

            if(HiddenWord.Len()!=Guess.Len())
                PrintLine(TEXT("Please try a %i letter isogram."), HiddenWord.Len());
            if(!IsIsogram(Guess))
                PrintLine("The word you typed is not a isogram.");
            else
                PrintLine("It is a isogram.");
        }
        return;
        PrintLine(TEXT("*****Congratulations!*****\nThat's a win.\nYou're great on this!"));
        EndGame();
    }
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press ENTER to play with another isogram..."));
}
