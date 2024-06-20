// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CPP_PlayerCharacter.generated.h"

class UCameraComponent;

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

protected:
	virtual void MoveForward(float Axis);
	virtual void MoveRight(float Axis);
	virtual void LookUp(float Axis);
	virtual void Turn(float Axis);
	virtual void StartJump();
	virtual void StopJump();

private:
	void CreateAndInitializeFPCamera();

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Player Character Components")
	UCameraComponent* FPCamera;
};
