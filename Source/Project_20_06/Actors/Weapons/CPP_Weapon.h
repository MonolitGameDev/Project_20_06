// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/SkeletalMeshActor.h"
#include "Interfaces/CPP_InteractionInterface.h"
#include "CPP_Weapon.generated.h"

UCLASS()
class PROJECT_20_06_API ACPP_Weapon : public ASkeletalMeshActor, public ICPP_InteractionInterface
{
	GENERATED_BODY()
	
public:
	ACPP_Weapon();
public:
	UFUNCTION()
	virtual void StopUsingWeaponManually(bool bValue);

	UFUNCTION(BlueprintCallable)
	virtual void UseWeapon();

	UFUNCTION(BlueprintCallable)
	virtual void StopUsingWeapon();

protected:
	virtual void BeginPlay() override;

protected:
	virtual void Interact_Implementation(AActor* Caller) override;
	virtual bool IsAbleToUseWeapon() const { return true; }

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Base Weapon Settings | Common")
	FName WeaponName = FName("");

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Base Weapon Settings | Common")
	bool bWeaponInUse = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Base Weapon Settings | Common")
	bool bAbleToUse = true;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Base Weapon Settings | Common")
	bool bStopedManually = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Base Weapon Settings | Common")
	class ACPP_PlayerCharacter* WeaponOwner = nullptr;
};
