// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "Interfaces/CPP_HasWeapon.h"
#include <Interfaces/CPP_InteractionInterface.h>

#include "Helpers/InteractParams.h"

#include "CPP_PlayerCharacter.generated.h"


class UCameraComponent;
class UCPP_HealthComponent;
class UCPP_InventoryComponent;

#define INTERACT_DISTANCE 350.0f

UCLASS()
class PROJECT_20_06_API ACPP_PlayerCharacter : public ACharacter, public ICPP_HasWeapon
{
	GENERATED_BODY()

public:
	ACPP_PlayerCharacter();

public:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Player Character Component")
	inline UCPP_HealthComponent* GetHealthComponent() const;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Player Character Component")
	FORCEINLINE UCPP_InventoryComponent* GetInventoryComponent() const
	{
		return InventoryComponent;
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Player Character Component")
	FORCEINLINE UCPP_WeaponComponent* GetWeaponComponent() const
	{
		return WeaponComponent;
	}
protected:
	UFUNCTION(BlueprintCallable)
	virtual void OnPlayerCharacterTakeAnyDamage
	(
		AActor* DamagedActor,
		float Damage,
		const class UDamageType* DamageType,
		class AController* InstigatedBy,
		AActor* DamageCauser
	);


protected:
	virtual void PickUpWeapon_Implementation(ACPP_Weapon* Weapon);

protected:
	virtual void MoveForward(float Axis);
	virtual void MoveRight(float Axis);
	virtual void LookUp(float Axis);
	virtual void Turn(float Axis);
	virtual void StartJump();
	virtual void StopJump();
	virtual void Interact();
	virtual void DropWeapon();

private:
	void CreateAndInitializeFPCamera();
	void CreateAndCheckHealthComponent();
	void CreateAndCheckInventoryComponent();
	void CreateAndCheckWeaponComponent();
	void InteractWithHitActor(const FInteractParams& InteractParams);
	FInteractParams CalculateVariablesForInteraction();

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Player Character Components")
	UCameraComponent* FPCamera; //Getter?

	UPROPERTY(EditDefaultsOnly, Category = "Player Character Components")
	UCPP_HealthComponent* HealthComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Player Character Components")
	UCPP_InventoryComponent* InventoryComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Player Character Components")
	UCPP_WeaponComponent* WeaponComponent;
};
