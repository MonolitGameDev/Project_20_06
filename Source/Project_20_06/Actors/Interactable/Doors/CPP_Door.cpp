// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Interactable/Doors/CPP_Door.h"

ACPP_Door::ACPP_Door()
{
	CreateAndInitializeDoorFrame();
	CreateAndInitializeDoor();
	CreateAndInitializeDoorTimeline();
}

void ACPP_Door::BeginPlay()
{
	Super::BeginPlay();
	
	CreateDoorTimelineHandler();
}

void ACPP_Door::Interact_Implementation(AActor* Caller)
{
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, TEXT("Interact with door"));

	OpenDoor(Caller);
}

void ACPP_Door::RotateDoor(float Value)
{
	FRotator rotator = FRotator(0.0f, Value * DoorRotateAngle, 0.0f);
	Door->SetRelativeRotation(rotator);
}

void ACPP_Door::OpenDoor(AActor* Caller)
{
	if (DoorTimeline->IsPlaying()) return;

	IsDoorClosed() ? StartOpeningDoorTimeline(Caller) :	StartClosingDoorTimeline();
	
	ChangeDoorClosedState();
}

void ACPP_Door::StartOpeningDoorTimeline(AActor* Caller)
{
	SetDoorOnSameSide(Caller);
	DoorTimeline->Play();
}

void ACPP_Door::StartClosingDoorTimeline()
{
	DoorTimeline->Reverse();
}

void ACPP_Door::ChangeDoorClosedState()
{
	bDoorClosed = !bDoorClosed;
}

void ACPP_Door::CreateAndInitializeDoorFrame()
{
	DoorFrame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorFrame"));
	check(DoorFrame);
	DoorFrame->SetupAttachment(RootComponent);
}

void ACPP_Door::CreateAndInitializeDoor()
{
	Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	check(Door);
	Door->SetupAttachment(DoorFrame);
}

void ACPP_Door::CreateAndInitializeDoorTimeline()
{
	DoorTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("DoorTimeline"));
	check(DoorTimeline);

	
}

void ACPP_Door::CreateDoorTimelineHandler()
{
	if (CurveFloat)
	{
		FOnTimelineFloat timelineProgress;
		timelineProgress.BindDynamic(this, &ACPP_Door::RotateDoor);
		DoorTimeline->AddInterpFloat(CurveFloat, timelineProgress);
	}
}
