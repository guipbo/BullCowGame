// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Welcome to the game."));
    PrintLine(TEXT("Guess the 4 letter word!"));

    InitGame();
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();

    if(HiddenWord!=Input){
        PrintLine(TEXT("You have lost!"));
        Lives -= 1;
        return;
    }
    PrintLine(TEXT("You have won!"));
}

void UBullCowCartridge::InitGame(){

    HiddenWord = TEXT("cake"); //Set the HiddenWord
    Lives = 3; //Set number of lives
}