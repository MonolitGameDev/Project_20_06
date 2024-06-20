// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Interactable/Doors/CPP_Door.h"

ACPP_Door::ACPP_Door()
{
	DoorFrame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorFrame"));
	Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));

	check(DoorFrame);
	check(Door);

	DoorFrame->SetupAttachment(RootComponent);
	Door->SetupAttachment(DoorFrame);
}

void ACPP_Door::BeginPlay()
{
	Super::BeginPlay();
	if (CurveFloat)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, TEXT("Namaracil"));
		FOnTimelineFloat timelineProgress;
		timelineProgress.BindDynamic(this, &ACPP_Door::OpenDoor);
		Timeline.AddInterpFloat(CurveFloat, timelineProgress);
	}
}

void ACPP_Door::Interact_Implementation(AActor* Caller)
{
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, TEXT("Interact with door"));

	if (bIsDoorClosed)
	{
		SetDoorOnSameSide(Caller);
		Timeline.Play();
	}
	else
	{
		Timeline.Reverse();
	}
	bIsDoorClosed = !bIsDoorClosed;
}

void ACPP_Door::OpenDoor(float Value)
{
	FRotator rotator = FRotator(0.0f, Value, 0.0f);
	Door->SetRelativeRotation(rotator);
}

void ACPP_Door::SetDoorOnSameSide(AActor* Actor)
{
	if (Actor)
	{
		FVector characterFV = Actor->GetActorForwardVector();
		FVector doorFV = GetActorForwardVector();
		DoorRotateAngle = (FVector::DotProduct(characterFV, doorFV) >= 0) ? DoorRotateAngle : -DoorRotateAngle;
	}
}
