// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/ActorComponent/CPP_InventoryComponent.h"


UCPP_InventoryComponent::UCPP_InventoryComponent()
{
	
	PrimaryComponentTick.bCanEverTick = true;

}

void UCPP_InventoryComponent::BeginPlay()
{
	Super::BeginPlay();
}