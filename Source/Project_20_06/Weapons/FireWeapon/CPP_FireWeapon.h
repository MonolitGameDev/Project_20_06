// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/CPP_Weapon.h"
#include "CPP_FireWeapon.generated.h"

UENUM(BlueprintType)
enum class EFireMode : uint8
{
	SingleShot UMETA(DisplayName = "Single Shot"),
	Automatic UMETA(DisplayName = "Automatic")
};

UCLASS()
class PROJECT_20_06_API ACPP_FireWeapon : public ACPP_Weapon
{
	GENERATED_BODY()

public:
	ACPP_FireWeapon();

	virtual void UseWeapon() override;
	virtual void StopUsingWeapon() override;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool GetIsAbleToAutoFire() const;

protected:
	UFUNCTION()
	virtual void Fire();

	virtual bool IsAbleToUseWeapon() const override;
	virtual void BeginPlay() override;
	virtual void Trace();

	void StartFiring();
	void StopFiring();

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon Settings")
	bool bAbleToAutoFire = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon Settings")
	EFireMode FireMode;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon Settings")
	float FireDelay = 0.1f;

	FTimerHandle FireTimerHandle;
};
