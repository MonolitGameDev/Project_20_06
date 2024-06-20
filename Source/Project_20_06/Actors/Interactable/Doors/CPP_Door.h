// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/Interactable/CPP_InteractableActor.h"
#include <Components/TimelineComponent.h>
#include "CPP_Door.generated.h"


/*
	FIX ASAP: CODE STYLE
*/

UCLASS()
class PROJECT_20_06_API ACPP_Door : public ACPP_InteractableActor
{
	GENERATED_BODY()
	
public:
	ACPP_Door();

protected:

	virtual void BeginPlay() override;

	virtual void Interact_Implementation(AActor* Caller) override;

	UFUNCTION()
	virtual void OpenDoor(float Value);

	FORCEINLINE virtual void SetDoorOnSameSide(AActor* Actor);

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Door | Components | Mesh")
	UStaticMeshComponent* DoorFrame;

	UPROPERTY(EditDefaultsOnly, Category = "Door | Components | Mesh")
	UStaticMeshComponent* Door;

	FTimeline Timeline;
	UPROPERTY(EditDefaultsOnly, Category = "Door | Settings | Timeline")
	class UCurveFloat* CurveFloat;

	bool bIsDoorClosed = true; //Getter, UPROPERTY?

	UPROPERTY(EditDefaultsOnly, Category = "Door | Settings")
	float DoorRotateAngle = 90.0f; //Is needed?
};
