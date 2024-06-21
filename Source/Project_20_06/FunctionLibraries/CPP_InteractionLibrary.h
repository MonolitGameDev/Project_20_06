// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Helpers/InteractParams.h"
#include "CPP_InteractionLibrary.generated.h"


UCLASS()
class PROJECT_20_06_API UCPP_InteractionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static bool Trace(AActor* Caller, FInteractParams& InteractParams);
};
