// Fill out your copyright notice in the Description page of Project Settings.

#include "Player/CPP_PlayerCharacter.h"
#include "Player/ActorComponent/CPP_HealthComponent.h"

#include "Camera/CameraComponent.h"

ACPP_PlayerCharacter::ACPP_PlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	CreateAndInitializeFPCamera();
	CreateAndCheckHealthComponent();
}

void ACPP_PlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

inline UCPP_HealthComponent* ACPP_PlayerCharacter::GetHealthComponent() const
{
	return HealthComponent;
}

void ACPP_PlayerCharacter::OnPlayerCharacterTakeAnyDamage
(
	AActor* DamagedActor,
	float Damage,
	const UDamageType* DamageType,
	AController* InstigatedBy,
	AActor* DamageCauser
)
{
	HealthComponent->AddHealth(static_cast<int32>(-Damage));
}

void ACPP_PlayerCharacter::MoveForward(float Axis)
{
	if (Axis == 0.0f) return;

	const FVector direction = GetActorForwardVector();

	AddMovementInput(direction, Axis);
}

void ACPP_PlayerCharacter::MoveRight(float Axis)
{
	if (Axis == 0.0f) return;

	const FVector direction = GetActorRightVector();

	AddMovementInput(direction, Axis);
}

void ACPP_PlayerCharacter::LookUp(float Axis)
{
	if (Axis == 0.0f) return;

	AddControllerPitchInput(Axis);
}

void ACPP_PlayerCharacter::Turn(float Axis)
{
	if (Axis == 0.0f) return;

	AddControllerYawInput(Axis);
}

void ACPP_PlayerCharacter::StartJump()
{
	Jump();
}

void ACPP_PlayerCharacter::StopJump()
{
	StopJumping();
}

void ACPP_PlayerCharacter::CreateAndInitializeFPCamera()
{
	FPCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FPCamera"));
	check(FPCamera);
	FPCamera->SetupAttachment(RootComponent);
	FPCamera->bUsePawnControlRotation = true;
}

void ACPP_PlayerCharacter::CreateAndCheckHealthComponent()
{
	HealthComponent = CreateDefaultSubobject<UCPP_HealthComponent>(TEXT("HealthComponent"));
	check(HealthComponent);
}

void ACPP_PlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(FName("MoveForward"), this, &ACPP_PlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis(FName("MoveRight"), this, &ACPP_PlayerCharacter::MoveRight);
	PlayerInputComponent->BindAxis(FName("LookUp"), this, &ACPP_PlayerCharacter::LookUp);
	PlayerInputComponent->BindAxis(FName("Turn"), this, &ACPP_PlayerCharacter::Turn);
	PlayerInputComponent->BindAction(FName("StartJump"), IE_Pressed, this, &ACPP_PlayerCharacter::StartJump);
	PlayerInputComponent->BindAction(FName("StopJump"), IE_Released, this, &ACPP_PlayerCharacter::StopJump);
}

