// Fill out your copyright notice in the Description page of Project Settings.

#include "Mighty.h"
#include "MightyGameMode.h"

#include "Card.h"

AMightyGameMode::AMightyGameMode()
{
}

void AMightyGameMode::InitGameState()
{
	game.reset(new Mighty::Game());

	game->Init(game);
	game->StartNewRound();

	for (const auto& pair : game->GetPlayers())
	{
		FVector2D direction;

		auto player = pair.second;
		auto standard = FVector2D(0, 0);

		switch (player->GetID())
		{
		case 0:
		{
			direction = FVector2D(1, 1);
		}
		break;

		case 1:
		{
			direction = FVector2D(1, 1);
		}
		break;

		case 2:
		{
			direction = FVector2D(-1, 1);
		}
		break;

		case 3:
		{
			direction = FVector2D(-1, -1);
		}
		break;

		case 4:
		{
			direction = FVector2D(1, -1);
		}
		break;
		}

		if (direction.X == -1.0f)
		{
			standard.X = 800;
		}
		if (direction.Y == -1.0f)
		{
			standard.Y = 600;
		}

		if (player->GetID() == 1)
		{
			standard.X += 800 / 3;
		}

		for (size_t i = 0; i < player->GetHandCardList().size(); ++i)
		{
			auto handCard = player->GetHandCardList()[i];
			auto type = handCard->GetType();
			float imageScale = 0.7f;

			auto* card = GetWorld()->SpawnActor<ACard>(FVector(0, 0, 0), FRotator(0, 0, 0));
			std::string imgName = Mighty::Util::GetCardResourceName(type);
			card->SetImage(imgName);

			auto position = FVector(standard.X + direction.X * (i + 0.5f) * imageScale * card->GetWidth(),
				-200,
				standard.Y + direction.Y * card->GetHeight() / 2 * imageScale);

			card->SetActorLocation(position);

			cardImageList[type] = card;
		}
	}
}