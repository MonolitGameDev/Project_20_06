// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Base/Actor/CPP_BaseActor.h"
#include "Interfaces/CPP_InteractionInterface.h"
#include "CPP_InteractableActor.generated.h"

UCLASS()
class PROJECT_20_06_API ACPP_InteractableActor : public ACPP_BaseActor, public ICPP_InteractionInterface
{
	GENERATED_BODY()

protected:
	virtual void Interact_Implementation(AActor* Caller) override {}
};
