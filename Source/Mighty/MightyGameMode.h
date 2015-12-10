// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "MightyGameMode.generated.h"

class ACard;

UCLASS()
class MIGHTY_API AMightyGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	AMightyGameMode();

	virtual void InitGameState() override;

private:
	std::shared_ptr<Mighty::Game> game;
	std::map<Mighty::CardType, ACard*> cardImageList;
};
