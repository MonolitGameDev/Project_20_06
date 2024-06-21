// Fill out your copyright notice in the Description page of Project Settings.


#include "Base/Actor/MoneyActors/CPP_MoneyActor.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "Components/SphereComponent.h"
#include <Player/CPP_PlayerCharacter.h>

ACPP_MoneyActor::ACPP_MoneyActor()
{
	CreateAndInitializeMoneyCollision();
	CreateAndInitializeMoneyMesh();
	CreateAndInitializeRotatingMovementComponent();
	DelayMoneyCollision();
}

void ACPP_MoneyActor::BeginPlay()
{
	Super::BeginPlay();
}

void ACPP_MoneyActor::CreateAndInitializeMoneyMesh()
{
	MoneyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MoneyMesh"));
	check(MoneyMesh);
	MoneyMesh->SetupAttachment(RootComponent);
}

void ACPP_MoneyActor::CreateAndInitializeMoneyCollision()
{
	MoneyCollision = CreateDefaultSubobject<USphereComponent>(TEXT("MoneyCollision"));
	check(MoneyCollision);
	MoneyCollision->SetupAttachment(RootComponent);
}

void ACPP_MoneyActor::CreateAndInitializeRotatingMovementComponent()
{
	RotatingMovementComponent = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("RotatingMovementComponent"));
	check(RotatingMovementComponent);
}

void ACPP_MoneyActor::DelayMoneyCollision()
{
	MoneyCollision->OnComponentBeginOverlap.AddDynamic(this, &ACPP_MoneyActor::OnMoneyCollisionBeginOverlap);
}

void ACPP_MoneyActor::OnMoneyCollisionBeginOverlap
(
	UPrimitiveComponent* OverlappedComponent, 
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult
)
{
	if (Cast<ACPP_PlayerCharacter>(OtherActor))
	{
		Destroy();
	}
}


