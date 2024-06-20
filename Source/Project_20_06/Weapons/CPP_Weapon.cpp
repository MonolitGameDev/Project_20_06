// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/CPP_Weapon.h"

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
