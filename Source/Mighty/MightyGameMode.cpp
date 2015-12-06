// Fill out your copyright notice in the Description page of Project Settings.

#include "Mighty.h"
#include "MightyGameMode.h"

#include "Card.h"

AMightyGameMode::AMightyGameMode()
{
}

void AMightyGameMode::InitGameState()
{
	UE_LOG(LogTemp, Warning, TEXT("InitGameState"));

	for (auto type : Mighty::CardTypes())
	{
		const auto location = FVector(0.0f, 0.0f, 0.f);

		// Spawn a block
		auto* card = GetWorld()->SpawnActor<ACard>(location, FRotator(0, 0, 0));
		std::string imgName = Mighty::Util::GetCardResourceName(type);
		auto fs = FString(imgName.c_str());
		UE_LOG(LogTemp, Warning, TEXT("%s"), *fs);
		card->SetImage(imgName);
	}
}