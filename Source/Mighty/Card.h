#pragma once

#include "GameFramework/Actor.h"
#include "Card.generated.h"

UCLASS(minimalapi)
class ACard : public AActor
{
	GENERATED_BODY()

public:
	ACard();

	void SetImage(const std::string& imgName);
};