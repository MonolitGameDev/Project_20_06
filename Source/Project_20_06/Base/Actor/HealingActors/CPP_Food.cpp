// Fill out your copyright notice in the Description page of Project Settings.


#include "Base/Actor/HealingActors/CPP_Food.h"

#include "Player/CPP_PlayerCharacter.h"
#include "Player/ActorComponent/CPP_HealthComponent.h"

#include "Components/SphereComponent.h"

ACPP_Food::ACPP_Food()
{
	CreateAndInitializeFoodMesh();
	CreateAndInitializeFoodCollision();

}

void ACPP_Food::BeginPlay()
{
	Super::BeginPlay();

}

void ACPP_Food::OnFoodCollisionBeginOverlap
(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult
)
{
	if (auto playerCharacter = Cast<ACPP_PlayerCharacter>(OtherActor))
	{
		playerCharacter->GetHealthComponent()->AddHealth(Health);
		Destroy();
	}
}

void ACPP_Food::CreateAndInitializeFoodMesh()
{
	FoodMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FoodMesh"));
	check(FoodMesh);
	FoodMesh->SetupAttachment(RootComponent);
}

void ACPP_Food::CreateAndInitializeFoodCollision()
{
	FoodCollision = CreateDefaultSubobject<USphereComponent>(TEXT("FoodCollision"));
	check(FoodCollision);
	FoodCollision->SetupAttachment(RootComponent);
	FoodCollision->OnComponentBeginOverlap.AddDynamic(this, &ACPP_Food::OnFoodCollisionBeginOverlap);
}
