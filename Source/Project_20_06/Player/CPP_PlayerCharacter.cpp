// Fill out your copyright notice in the Description page of Project Settings.

#include "Player/CPP_PlayerCharacter.h"
#include "Player/ActorComponent/CPP_HealthComponent.h"
#include "Player/ActorComponent/CPP_WeaponComponent.h"
#include "Player/ActorComponent/CPP_InventoryComponent.h"
#include "FunctionLibraries/CPP_InteractionLibrary.h"
#include <Kismet/KismetMathLibrary.h>

#include "Camera/CameraComponent.h"

#include <Interfaces/CPP_InteractionInterface.h>

ACPP_PlayerCharacter::ACPP_PlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	CreateAndCheckInventoryComponent();
	CreateAndInitializeFPCamera();
	CreateAndCheckHealthComponent();
	CreateAndCheckWeaponComponent();
}

void ACPP_PlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

}

//FORCEINLINE, Implement inside class
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

void ACPP_PlayerCharacter::PickUpWeapon_Implementation(ACPP_Weapon* Weapon)
{
	if (Weapon)
	{
		GetWeaponComponent()->PickUpWeapon(Weapon);
	}
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

void ACPP_PlayerCharacter::Interact()
{
	FInteractParams interactParams = CalculateVariablesForInteraction();
	DrawDebugLine(GetWorld(), interactParams.Start, interactParams.End, FColor::Blue, false, 2.0f, static_cast<uint8>(0U), 0.5f);
	if (UCPP_InteractionLibrary::Trace(this, interactParams))
	{
		InteractWithHitActor(interactParams);
	}
}

void ACPP_PlayerCharacter::DropWeapon()
{
	UCPP_WeaponComponent* weaponComponent = GetWeaponComponent();
	weaponComponent->DropWeapon(weaponComponent->GetCurrentWeapon());
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

void ACPP_PlayerCharacter::CreateAndCheckInventoryComponent()
{
	InventoryComponent = CreateDefaultSubobject<UCPP_InventoryComponent>(TEXT("InventoryComponent"));
	check(InventoryComponent);
}

void ACPP_PlayerCharacter::CreateAndCheckWeaponComponent()
{
	WeaponComponent = CreateDefaultSubobject<UCPP_WeaponComponent>(TEXT("WeaponComponent"));
	check(WeaponComponent);
}

void ACPP_PlayerCharacter::InteractWithHitActor(const FInteractParams& InteractParams)
{
	if (AActor* actor = InteractParams.HitResult.GetActor())
	{
		if (actor->Implements<UCPP_InteractionInterface>())
		{
			ICPP_InteractionInterface::Execute_Interact(actor, this);
		}
	}
}

FInteractParams ACPP_PlayerCharacter::CalculateVariablesForInteraction()
{
	FInteractParams result;
	FVector lookDirection = UKismetMathLibrary::Conv_RotatorToVector(GetController()->GetControlRotation());
	result.Distance = INTERACT_DISTANCE;
	result.Start = FPCamera->GetComponentLocation();
	result.End = result.Start + lookDirection * result.Distance;
	result.CollisionQueryParams.AddIgnoredActor(this);
	return result;
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
	PlayerInputComponent->BindAction(FName("Interact"), IE_Pressed, this, &ACPP_PlayerCharacter::Interact);
	PlayerInputComponent->BindAction(FName("DropWeapon"), IE_Pressed, this, &ACPP_PlayerCharacter::DropWeapon);
}

