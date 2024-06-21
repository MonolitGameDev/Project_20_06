// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CPP_WeaponComponent.generated.h"

class ACPP_Weapon;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECT_20_06_API UCPP_WeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCPP_WeaponComponent();

public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Inventory Component | Weapons")
	FORCEINLINE ACPP_Weapon* GetCurrentWeapon() const
	{
		return CurrentWeapon;
	}

public:
	virtual void DropWeapon(ACPP_Weapon* WeaponToDrop);
	virtual void PickUpWeapon(ACPP_Weapon* WeaponToPickUp);
protected:
	virtual void BeginPlay() override;
	
protected:
	UPROPERTY()
	ACPP_Weapon* CurrentWeapon;
};
