// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Base/Actor/CPP_BaseActor.h"
#include "CPP_Food.generated.h"

class ACPP_PlayerCharacter;
class USphereComponent;

UCLASS()
class PROJECT_20_06_API ACPP_Food : public ACPP_BaseActor
{
	GENERATED_BODY()
	
public:
	ACPP_Food();

protected:
	virtual void BeginPlay() override;

protected:
	UFUNCTION()
	virtual void OnFoodCollisionBeginOverlap
	(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
	);

private:
	void CreateAndInitializeFoodMesh();
	void CreateAndInitializeFoodCollision();

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Food Components")
	UStaticMeshComponent* FoodMesh;

	UPROPERTY(EditDefaultsOnly, Category = "Food Components")
	USphereComponent* FoodCollision;

	UPROPERTY(EditAnyWhere, Category = "Food Properties")
	int32 Health = 10;
};
