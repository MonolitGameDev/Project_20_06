// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_BaseActor.generated.h"

UCLASS()
class PROJECT_20_06_API ACPP_BaseActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ACPP_BaseActor();

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Actor | Components")
	USceneComponent* Root;
};
