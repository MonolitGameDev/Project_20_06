// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Weapons/CPP_Weapon.h"

#include "Player/CPP_PlayerCharacter.h"
#include "Player/ActorComponent/CPP_InventoryComponent.h"

#include "Interfaces/CPP_HasWeapon.h"

ACPP_Weapon::ACPP_Weapon()
{
	//Collapse into method
	auto Mesh = GetSkeletalMeshComponent();
	Mesh->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);
}

void ACPP_Weapon::StopUsingWeaponManually(bool bValue)
{
	bStopedManually = bValue;
}

void ACPP_Weapon::UseWeapon()
{
	bWeaponInUse = true;
}

void ACPP_Weapon::StopUsingWeapon()
{
	bWeaponInUse = false;
}

void ACPP_Weapon::BeginPlay()
{
	Super::BeginPlay();
}

void ACPP_Weapon::Interact_Implementation(AActor* Caller)
{
	if (Caller && Caller->Implements<UCPP_HasWeapon>())
	{
		ICPP_HasWeapon::Execute_PickUpWeapon(Caller, this);
	}
}
