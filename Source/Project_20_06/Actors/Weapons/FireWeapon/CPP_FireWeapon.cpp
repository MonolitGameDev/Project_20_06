// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Weapons/FireWeapon/CPP_FireWeapon.h"
#include "Player/CPP_PlayerCharacter.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/World.h"
#include "TimerManager.h"

ACPP_FireWeapon::ACPP_FireWeapon()
{
	FireMode = EFireMode::SingleShot;
}

void ACPP_FireWeapon::UseWeapon()
{
	if (IsAbleToUseWeapon() && !bWeaponInUse)
	{
		StartFiring();
	}
}

void ACPP_FireWeapon::StopUsingWeapon()
{
	StopFiring();
	ACPP_Weapon::StopUsingWeapon();
}

bool ACPP_FireWeapon::GetIsAbleToAutoFire() const
{
	return bAbleToAutoFire;
}

void ACPP_FireWeapon::Fire()
{
	Trace();

	if (FireMode == EFireMode::Automatic && bWeaponInUse) //Collapse it in a method
	{
		GetWorld()->GetTimerManager().SetTimer(FireTimerHandle, this, &ACPP_FireWeapon::Fire, FireDelay, false);
	}
}

//FORCEINLINE, Implement inside class
bool ACPP_FireWeapon::IsAbleToUseWeapon() const
{
	return bAbleToUse;
}

void ACPP_FireWeapon::BeginPlay()
{
	Super::BeginPlay();
}

void ACPP_FireWeapon::Trace()
{
	/*
		Rewrite using a struct (make one)
		And make a function library
	*/

	FVector Start = WeaponOwner->GetActorLocation();
	FRotator Rotation = WeaponOwner->GetControlRotation();
	FVector End = Start + Rotation.Vector() * 10000.0f;

	FHitResult HitResult;
	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this);
	CollisionParams.AddIgnoredActor(WeaponOwner);

	bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, CollisionParams);
	DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 1.0f, 0, 1.0f);

	if (bHit)
	{
		DrawDebugPoint(GetWorld(), HitResult.Location, 10.0f, FColor::Green, false, 1.0f);
	}
}

void ACPP_FireWeapon::StartFiring()
{
	bWeaponInUse = true;

	if (FireMode == EFireMode::SingleShot) //switch
	{
		Fire();
		StopUsingWeapon();
	}
	else if (FireMode == EFireMode::Automatic)
	{
		Fire();
	}
}

void ACPP_FireWeapon::StopFiring()
{
	bWeaponInUse = false;
	GetWorld()->GetTimerManager().ClearTimer(FireTimerHandle);
}