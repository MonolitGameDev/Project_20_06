// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CollisionQueryParams.h"
#include "InteractParams.generated.h"

USTRUCT(BlueprintType)
struct PROJECT_20_06_API FInteractParams
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Distance;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector Start;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector End;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FHitResult HitResult;

	FCollisionQueryParams CollisionQueryParams;
};
