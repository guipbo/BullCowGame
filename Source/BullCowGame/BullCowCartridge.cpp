// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    
    SetupGame();
    PrintLine(TEXT("Welcome to the game."));
    PrintLine(TEXT("HiddenWord: %s"), *HiddenWord);
    PrintLine(TEXT("Guess the %i letters word!"), HiddenWord.Len());

}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();

    if(HiddenWord!=Input){
        Lives -= 1;

        if(Lives <= 0)
        {
            PrintLine(TEXT("You are out of lives.\nThe word was: %s"), *HiddenWord);
            PrintLine(TEXT("Lets try again with another word?"));
            return;
        }

        if(HiddenWord.Len()!=Input.Len())
            PrintLine(TEXT("Please try a %i letters word."), HiddenWord.Len());

        PrintLine(TEXT("You can do this!\nYou still have %i live(s)."), Lives);
        return;
    }
    PrintLine(TEXT("You have won!"));
}

void UBullCowCartridge::SetupGame(){

    HiddenWord = TEXT("cake"); //Set the HiddenWord
    Lives = 5; //Set number of lives
}