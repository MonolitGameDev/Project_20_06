// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CPP_HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECT_20_06_API UCPP_HealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCPP_HealthComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Health Component")
	inline int32 GetHealth() const;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Health Component")
	inline bool IsAlive() const;

	void AddHealth(int32 Value);

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Health Component")
	int32 Health = 100;

	UPROPERTY(EditDefaultsOnly, Category = "Health Component")
	bool bAlive = true;
};
