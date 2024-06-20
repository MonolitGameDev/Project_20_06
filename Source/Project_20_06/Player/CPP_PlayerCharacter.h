// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CPP_PlayerCharacter.generated.h"

class UCameraComponent;
class UCPP_HealthComponent;

UCLASS()
class PROJECT_20_06_API ACPP_PlayerCharacter : public ACharacter
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
	virtual void MoveForward(float Axis);
	virtual void MoveRight(float Axis);
	virtual void LookUp(float Axis);
	virtual void Turn(float Axis);
	virtual void StartJump();
	virtual void StopJump();
	virtual void Interact();

private:
	void CreateAndInitializeFPCamera();
	void CreateAndCheckHealthComponent();

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Player Character Components")
	UCameraComponent* FPCamera; //Getter?

	UPROPERTY(EditDefaultsOnly, Category = "Player Character Components")
	UCPP_HealthComponent* HealthComponent;
};
