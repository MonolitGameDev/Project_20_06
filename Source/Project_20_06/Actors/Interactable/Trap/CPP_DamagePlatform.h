// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/Interactable/CPP_InteractableActor.h"
#include "CPP_DamagePlatform.generated.h"

class UBoxComponent;

UCLASS()
class PROJECT_20_06_API ACPP_DamagePlatform : public ACPP_InteractableActor
{
	GENERATED_BODY()

public:
	ACPP_DamagePlatform();

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void TryApplyDamage();

protected:
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* Platform;

	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* DamageCollision;
	
};
