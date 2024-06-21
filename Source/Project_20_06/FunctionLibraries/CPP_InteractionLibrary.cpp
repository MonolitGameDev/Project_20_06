// Fill out your copyright notice in the Description page of Project Settings.


#include "FunctionLibraries/CPP_InteractionLibrary.h"

bool UCPP_InteractionLibrary::Trace(AActor* Caller, FInteractParams& InteractParams)
{
	return Caller->GetWorld()->LineTraceSingleByChannel
	(
		InteractParams.HitResult,
		InteractParams.Start,
		InteractParams.End,
		ECC_Visibility,
		InteractParams.CollisionQueryParams
	);

}
