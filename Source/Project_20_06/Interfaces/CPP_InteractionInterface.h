// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CPP_InteractionInterface.generated.h"

UINTERFACE(MinimalAPI)
class UCPP_InteractionInterface : public UInterface
{
	GENERATED_BODY()
};

class PROJECT_20_06_API ICPP_InteractionInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	void Interact(class AActor* Caller);
};
