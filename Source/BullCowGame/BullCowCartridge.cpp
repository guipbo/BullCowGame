// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Welcome to the game."));
    PrintLine(TEXT("Guess the -X- letters word!"));

    SetupGame();
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();

    if(HiddenWord!=Input){
        Lives -= 1;

        if(Lives <= 0)
        {
            PrintLine(TEXT("You have lost!"));
            return;
        }

        if(HiddenWord.Len()!=Input.Len())
            PrintLine(TEXT("Please try a -X- letters word."));

        PrintLine(TEXT("You can do this!\nYou still have -X- lives."));
        return;
    }
    PrintLine(TEXT("You have won!"));
}

void UBullCowCartridge::SetupGame(){

    HiddenWord = TEXT("cake"); //Set the HiddenWord
    Lives = 2; //Set number of lives
}