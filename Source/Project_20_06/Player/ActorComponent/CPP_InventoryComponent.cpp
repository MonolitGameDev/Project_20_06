// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/ActorComponent/CPP_InventoryComponent.h"

#include "Actors/Interactable/Items/CPP_Item.h"

UCPP_InventoryComponent::UCPP_InventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	CreateInventory(Inventory, InventorySize);
}

bool UCPP_InventoryComponent::AddToInventory(const FActorItemInfo& ItemInfo)
{
	return AddUnstackable(ItemInfo);
}

bool UCPP_InventoryComponent::FindInInventory(UClass* ItemClass)
{
	return Inventory.FindByPredicate([&](const FActorItemInfo& ItemInfo)
		{
			return ItemInfo.Class == ItemClass;
		}) != nullptr;
}

void UCPP_InventoryComponent::CreateInventory(TArray<FActorItemInfo>& Inventory, int32 InventorySize)
{
	for (int32 i = 0; i < InventorySize; ++i)
	{
		Inventory.Add(FActorItemInfo::CreateEmptyItemInfo(i));
	}
}

bool UCPP_InventoryComponent::AddUnstackable(const FActorItemInfo& ItemInfo)
{
	int32 emptyIndex;
	if (FindEmptySlot(emptyIndex))
	{
		Inventory[emptyIndex] = ItemInfo;
		Inventory[emptyIndex].Index = emptyIndex;
		return true;
	}
	return false;
}

bool UCPP_InventoryComponent::FindEmptySlot(int32& Index)
{
	FActorItemInfo temp;
	return Inventory.Find(temp, Index);
}
