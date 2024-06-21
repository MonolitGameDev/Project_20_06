// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/ActorComponent/CPP_WeaponComponent.h"

#include "Actors/Weapons/CPP_Weapon.h"

UCPP_WeaponComponent::UCPP_WeaponComponent()
{

}

void UCPP_WeaponComponent::DropWeapon(ACPP_Weapon* WeaponToDrop)
{
	if (WeaponToDrop)
	{
		WeaponToDrop->Destroy();
		WeaponToDrop = nullptr;
	}
}

void UCPP_WeaponComponent::PickUpWeapon(ACPP_Weapon* WeaponToPickUp)
{
	if (WeaponToPickUp)
	{
		CurrentWeapon = WeaponToPickUp;
	}
}

void UCPP_WeaponComponent::BeginPlay()
{
	Super::BeginPlay();

}
