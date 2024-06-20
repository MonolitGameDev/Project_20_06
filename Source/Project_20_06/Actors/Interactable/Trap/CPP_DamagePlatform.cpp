// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Interactable/Trap/CPP_DamagePlatform.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

ACPP_DamagePlatform::ACPP_DamagePlatform()
{
	Platform = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Platform"));
	DamageCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("DamageCollision"));

	check(Platform);
	check(DamageCollision);

	Platform->SetupAttachment(RootComponent);
	DamageCollision->SetupAttachment(RootComponent);
}

void ACPP_DamagePlatform::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle th;
	FTimerDelegate td;
	td.BindUFunction(this, FName("TryApplyDamage"));

	GetWorld()->GetTimerManager().SetTimer(th, td, 1.0f, true, 1.0f);
}

void ACPP_DamagePlatform::TryApplyDamage()
{
	TArray<AActor*> overlappingActor;
	DamageCollision->GetOverlappingActors(overlappingActor);

	for (AActor* actor : overlappingActor)
	{
		UGameplayStatics::ApplyDamage(actor, 20.0f, nullptr, this, UDamageType::StaticClass());
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, "-20 hp");
	}
}
