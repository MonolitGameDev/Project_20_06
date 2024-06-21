// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Base/Actor/CPP_BaseActor.h"
#include "CPP_MoneyActor.generated.h"

class USphereComponent;
class URotatingMovementComponent;

UCLASS()
class PROJECT_20_06_API ACPP_MoneyActor : public ACPP_BaseActor
{
	GENERATED_BODY()

public:
	ACPP_MoneyActor();
		
protected:

	UFUNCTION()
	void OnMoneyCollisionBeginOverlap
	(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
	);

protected:
	virtual void BeginPlay() override;


private:
	void CreateAndInitializeMoneyCollision();
	void CreateAndInitializeMoneyMesh();
	void CreateAndInitializeRotatingMovementComponent();
	void DelayMoneyCollision();
	

protected:
	UPROPERTY(EditAnywhere, Category = "Money")
	int32 MoneyParam = 25;

	UPROPERTY(EditDefaultsOnly, Category="Money")
	UStaticMeshComponent* MoneyMesh;

	UPROPERTY(EditDefaultsOnly, Category = "Money")
	USphereComponent* MoneyCollision;

	UPROPERTY(EditDefaultsOnly, Category = "Money")
	URotatingMovementComponent* RotatingMovementComponent;
};
