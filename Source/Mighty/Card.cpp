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

	auto* obj = static_cast<UPaperSprite*>(StaticLoadObject(UPaperSprite::StaticClass(), nullptr, TEXT("/Game/Resources/card_images/jb_sprite.jb_sprite"), TEXT("")));
	spriteComp->SetSprite(obj);
}

// Called every frame
void ACard::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

