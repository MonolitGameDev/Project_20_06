// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/Interactable/CPP_InteractableActor.h"
#include "Components/TimelineComponent.h"
#include "CPP_Door.generated.h"


UCLASS()
class PROJECT_20_06_API ACPP_Door : public ACPP_InteractableActor
{
	GENERATED_BODY()
	
public:
	ACPP_Door();

protected:
	UFUNCTION(BlueprintCallable)
	virtual void RotateDoor(float Value);

	UFUNCTION(BlueprintCallable)
	virtual void OpenDoor(AActor* Caller);

public:
	UFUNCTION(BlueprintPure)
	FORCEINLINE bool IsDoorClosed() const 
	{
		return bDoorClosed;
	}

protected:
	FORCEINLINE void SetDoorOnSameSide(AActor* Actor)
	{
		if (Actor)
		{
			FVector characterFV = Actor->GetActorForwardVector();
			FVector doorFV = GetActorForwardVector();
			DoorRotateAngle = (FVector::DotProduct(characterFV, doorFV) >= 0) ? DoorRotateAngle : -DoorRotateAngle;
		}
	}

protected:
	virtual void BeginPlay() override;

protected:
	virtual void Interact_Implementation(AActor* Caller) override;

protected:
	void StartOpeningDoorTimeline(AActor* Caller);
	void StartClosingDoorTimeline();
	void ChangeDoorClosedState();

private:
	void CreateAndInitializeDoorFrame();
	void CreateAndInitializeDoor();
	void CreateAndInitializeDoorTimeline();
	void CreateDoorTimelineHandler();

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Door | Components | Mesh")
	UStaticMeshComponent* DoorFrame;

	UPROPERTY(EditDefaultsOnly, Category = "Door | Components | Mesh")
	UStaticMeshComponent* Door;

	UPROPERTY(EditDefaultsOnly, Category = "Door | Components | Timeline")
	UTimelineComponent* DoorTimeline;

	UPROPERTY(EditDefaultsOnly, Category = "Door | Settings | Timeline")
	class UCurveFloat* CurveFloat;

	UPROPERTY(EditAnywhere, Category = "Door | Settings")
	bool bDoorClosed = true;

	UPROPERTY(EditDefaultsOnly, Category = "Door | Settings")
	float DoorRotateAngle = 90.0f;
};
