// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Console/Cartridge.h"
#include "BullCowCartridge.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BULLCOWGAME_API UBullCowCartridge : public UCartridge
{
	GENERATED_BODY()

	public:
	virtual void BeginPlay() override;
	virtual void OnInput(const FString& Input) override;
	void SetupGame(int32 difficulty);
	void EndGame();

	// Your declarations go below!
	private:
		int32 Difficulty;
		FString EasyWords[100] = {TEXT("oh"),TEXT("ex"),TEXT("do"),TEXT("as"),TEXT("he"),TEXT("if"),TEXT("so"),TEXT("me"),TEXT("on"),TEXT("am"),TEXT("an"),TEXT("be"),TEXT("us"),TEXT("by"),TEXT("up"),TEXT("go"),TEXT("at"),TEXT("in"),TEXT("of"),TEXT("no"),TEXT("we"),TEXT("my"),TEXT("or"),TEXT("to"),TEXT("is"),TEXT("fun"),TEXT("leg"),TEXT("ego"),TEXT("dip"),TEXT("gap"),TEXT("put"),TEXT("key"),TEXT("aid"),TEXT("age"),TEXT("pen"),TEXT("map"),TEXT("tip"),TEXT("log"),TEXT("pop"),TEXT("gem"),TEXT("raw"),TEXT("get"),TEXT("new"),TEXT("fur"),TEXT("shy"),TEXT("eat"),TEXT("act"),TEXT("old"),TEXT("bar"),TEXT("can"),TEXT("pay"),TEXT("fee"),TEXT("arm"),TEXT("jam"),TEXT("tin"),TEXT("rub"),TEXT("pig"),TEXT("kid"),TEXT("club"),TEXT("hell"),TEXT("mail"),TEXT("gown"),TEXT("core"),TEXT("even"),TEXT("wake"),TEXT("fish"),TEXT("pour"),TEXT("bald"),TEXT("area"),TEXT("beer"),TEXT("mean"),TEXT("heal"),TEXT("path"),TEXT("taxi"),TEXT("tank"),TEXT("bark"),TEXT("bolt"),TEXT("tone"),TEXT("gold"),TEXT("kick"),TEXT("lake"),TEXT("slam"),TEXT("link"),TEXT("feel"),TEXT("corn"),TEXT("cord"),TEXT("tree"),TEXT("late"),TEXT("lead"),TEXT("flex"),TEXT("bulb"),TEXT("plan")};
		FString NormalWords[100] = {TEXT("dirty"),TEXT("skate"),TEXT("stool"),TEXT("shine"),TEXT("grant"),TEXT("store"),TEXT("tempt"),TEXT("error"),TEXT("black"),TEXT("trade"),TEXT("route"),TEXT("sweep"),TEXT("chest"),TEXT("throw"),TEXT("brown"),TEXT("seize"),TEXT("basic"),TEXT("metal"),TEXT("steak"),TEXT("deter"),TEXT("place"),TEXT("final"),TEXT("scale"),TEXT("drift"),TEXT("track"),TEXT("kneel"),TEXT("think"),TEXT("index"),TEXT("album"),TEXT("width"),TEXT("sound"),TEXT("bring"),TEXT("piano"),TEXT("spray"),TEXT("tight"),TEXT("frame"),TEXT("floor"),TEXT("blade"),TEXT("queue"),TEXT("wagon"),TEXT("chair"),TEXT("pilot"),TEXT("climb"),TEXT("brake"),TEXT("stick"),TEXT("wrist"),TEXT("layer"),TEXT("smell"),TEXT("knife"),TEXT("radio"),TEXT("origin"),TEXT("trench"),TEXT("driver"),TEXT("stable"),TEXT("remedy"),TEXT("pastel"),TEXT("island"),TEXT("tactic"),TEXT("expose"),TEXT("strict"),TEXT("screen"),TEXT("demand"),TEXT("wealth"),TEXT("ladder"),TEXT("advice"),TEXT("notion"),TEXT("person"),TEXT("waiter"),TEXT("cereal"),TEXT("wonder"),TEXT("galaxy"),TEXT("oppose"),TEXT("deputy"),TEXT("marble"),TEXT("absent"),TEXT("delete"),TEXT("excuse"),TEXT("helmet"),TEXT("market"),TEXT("revive"),TEXT("salmon"),TEXT("button"),TEXT("reform"),TEXT("retain"),TEXT("regard"),TEXT("threat"),TEXT("endure"),TEXT("hiccup"),TEXT("useful"),TEXT("forest"),TEXT("forbid"),TEXT("return"),TEXT("scheme"),TEXT("repeat"),TEXT("medium"),TEXT("kidney"),TEXT("layout"),TEXT("linger"),TEXT("health"),TEXT("estate")};
		FString HardWords[100] = {TEXT("quality"),TEXT("manager"),TEXT("network"),TEXT("concede"),TEXT("pattern"),TEXT("jealous"),TEXT("profile"),TEXT("meeting"),TEXT("glacier"),TEXT("squeeze"),TEXT("eyebrow"),TEXT("opposed"),TEXT("reverse"),TEXT("symptom"),TEXT("tragedy"),TEXT("absence"),TEXT("torture"),TEXT("justify"),TEXT("present"),TEXT("inquiry"),TEXT("healthy"),TEXT("climate"),TEXT("recruit"),TEXT("decline"),TEXT("falsify"),TEXT("loyalty"),TEXT("thought"),TEXT("curtain"),TEXT("include"),TEXT("tourist"),TEXT("surgeon"),TEXT("install"),TEXT("tension"),TEXT("counter"),TEXT("respect"),TEXT("emotion"),TEXT("freight"),TEXT("visible"),TEXT("welcome"),TEXT("compact"),TEXT("discuss"),TEXT("plastic"),TEXT("unaware"),TEXT("freckle"),TEXT("bathtub"),TEXT("failure"),TEXT("privacy"),TEXT("pumpkin"),TEXT("strange"),TEXT("sweater"),TEXT("ambition"),TEXT("stubborn"),TEXT("carriage"),TEXT("vertical"),TEXT("official"),TEXT("disaster"),TEXT("invasion"),TEXT("district"),TEXT("generate"),TEXT("governor"),TEXT("contrary"),TEXT("referral"),TEXT("activate"),TEXT("relative"),TEXT("observer"),TEXT("ignorant"),TEXT("standard"),TEXT("contract"),TEXT("resident"),TEXT("cucumber"),TEXT("seasonal"),TEXT("progress"),TEXT("solution"),TEXT("definite"),TEXT("slippery"),TEXT("reporter"),TEXT("joystick"),TEXT("suppress"),TEXT("terminal"),TEXT("workshop"),TEXT("instinct"),TEXT("describe"),TEXT("elephant"),TEXT("autonomy"),TEXT("vigorous"),TEXT("finished"),TEXT("hesitate"),TEXT("threaten"),TEXT("congress"),TEXT("implicit"),TEXT("training"),TEXT("scenario"),TEXT("minority"),TEXT("spectrum"),TEXT("argument"),TEXT("classify"),TEXT("excavate"),TEXT("reaction"),TEXT("marriage"),TEXT("memorial")};
		FString HiddenWord;
		int32 Lives;
		bool bGameOver;
};
