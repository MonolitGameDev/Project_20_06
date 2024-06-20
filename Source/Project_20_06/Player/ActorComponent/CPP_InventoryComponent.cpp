// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/ActorComponent/CPP_InventoryComponent.h"

#include "Actors/Weapons/CPP_Weapon.h"

UCPP_InventoryComponent::UCPP_InventoryComponent()
{
	
	PrimaryComponentTick.bCanEverTick = true;

}

void UCPP_InventoryComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UCPP_InventoryComponent::PickUpWeapon(ACPP_Weapon* Weapon)
{
	if (Weapon)
	{
		CurrentWeapon = Weapon;
	}
}

void UCPP_InventoryComponent::DropWeapon(ACPP_Weapon* WeaponToDrop)
{
	if (WeaponToDrop)
	{
		WeaponToDrop->Destroy();
		WeaponToDrop = nullptr;
	}
}
