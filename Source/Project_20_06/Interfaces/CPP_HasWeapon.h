// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CPP_HasWeapon.generated.h"

class ACPP_Weapon;

UINTERFACE(MinimalAPI)
class UCPP_HasWeapon : public UInterface
{
	GENERATED_BODY()
};

class PROJECT_20_06_API ICPP_HasWeapon
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintNativeEvent)
	void PickUpWeapon(ACPP_Weapon* Weapon);
};
