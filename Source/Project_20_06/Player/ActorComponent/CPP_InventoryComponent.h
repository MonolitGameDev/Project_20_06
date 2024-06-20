// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CPP_InventoryComponent.generated.h"

class ACPP_Weapon;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECT_20_06_API UCPP_InventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCPP_InventoryComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void PickUpWeapon(ACPP_Weapon* Weapon);
	virtual void DropWeapon(ACPP_Weapon* WeaponToDrop);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Inventory Component | Weapons")
	FORCEINLINE ACPP_Weapon* GetCurrentWeapon() const
	{
		return CurrentWeapon;
	}

protected:	
	UPROPERTY()
	int32 InventorySize = 10;

	UPROPERTY()
	ACPP_Weapon* CurrentWeapon;
};
