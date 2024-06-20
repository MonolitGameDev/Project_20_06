// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/ActorComponent/CPP_HealthComponent.h"


UCPP_HealthComponent::UCPP_HealthComponent()
{
	//TRUE?
	PrimaryComponentTick.bCanEverTick = true;
}

void UCPP_HealthComponent::BeginPlay()
{
	Super::BeginPlay();
}

//FORCEINLINE, Implement inside class
inline int32 UCPP_HealthComponent::GetHealth() const
{
	return Health;
}

//FORCEINLINE, Implement inside class
inline bool UCPP_HealthComponent::IsAlive() const
{
	return bAlive;
}

void UCPP_HealthComponent::AddHealth(int32 Value)
{
	auto sum = Health + Value;
	if (sum >= 100) //Collapse into a method
	{
		Health = 100;
	}
	else if (sum <= 0) //Collapse into a method
	{
		bAlive = false;
	}
	else
	{
		Health = sum;
	}
}
