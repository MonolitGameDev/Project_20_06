// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CPP_InventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECT_20_06_API UCPP_InventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCPP_InventoryComponent();

protected:
	virtual void BeginPlay() override;

protected:	
	UPROPERTY()
	int32 InventorySize = 10;
		
};
