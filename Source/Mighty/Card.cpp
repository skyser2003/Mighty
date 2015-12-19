// Fill out your copyright notice in the Description page of Project Settings.

#include "Mighty.h"
#include "Card.h"

#include "PaperSpriteActor.h"
#include "PaperSprite.h"
#include "PaperSpriteComponent.h"

// Sets default values
ACard::ACard()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = spriteComp = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("PrimarySprite"));

	ConstructorHelpers::FObjectFinder<UPaperSprite> Material(TEXT("/Game/Resources/card_images/jr_sprite.jr_sprite"));
	if (Material.Object != nullptr)
	{
		auto* sprite = (UPaperSprite*)Material.Object;
		spriteComp->SetSprite(sprite);
	}
}

// Called when the game starts or when spawned
void ACard::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACard::SetImage(const std::string& imgName)
{
	std::string texName = "/Game/Resources/card_images/" + imgName + "." + imgName;
	std::string resourceName = "/Game/Resources/card_images/" + imgName + "_sprite." + imgName + "_sprite";

	auto texFs = FString(texName.c_str());
	auto fs = FString(resourceName.c_str());

	auto* tex = static_cast<UTexture2D*>(StaticLoadObject(UTexture2D::StaticClass(), nullptr, *texFs, TEXT("")));

	FSpriteAssetInitParameters params;
	params.SetTextureAndFill(tex);

	auto* sprite = NewObject<UPaperSprite>(spriteComp, UPaperSprite::StaticClass());
	sprite->InitializeSprite(params);

	spriteComp->SetSprite(sprite);
}