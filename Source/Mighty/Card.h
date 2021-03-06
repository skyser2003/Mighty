// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Card.generated.h"

class UPaperSpriteComponent;

UCLASS(minimalapi)
class ACard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACard();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	void SetImage(const std::string& imgName);

	int GetWidth() const;
	int GetHeight() const;

private:
	UPaperSpriteComponent* spriteComp = nullptr;
};