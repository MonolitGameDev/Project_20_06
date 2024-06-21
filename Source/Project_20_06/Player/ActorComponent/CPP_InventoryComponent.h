// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Actors/Interactable/Items/ActorItemInfo.h"
#include "CPP_InventoryComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECT_20_06_API UCPP_InventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCPP_InventoryComponent();

public:
	UFUNCTION(BlueprintCallable, Category = "Inventory Component | Inventory")
	FORCEINLINE void GetInventory(TArray<FActorItemInfo>& const OutInventory) const
	{
		OutInventory = Inventory;
	}

	UFUNCTION(BlueprintCallable, Category = "Inventory Component | Inventory")
	virtual bool AddToInventory(const FActorItemInfo& ItemInfo);

	UFUNCTION(BlueprintCallable, Category = "Inventory Component | Inventory")
	virtual bool FindInInventory(UClass* ItemClass);

protected:
	static void CreateInventory(TArray<FActorItemInfo>& Inventory, int32 InventorySize);
	bool AddUnstackable(const FActorItemInfo& ItemInfo);

private:
	bool FindEmptySlot(int32& Index);

protected:	
	UPROPERTY()
	int32 InventorySize = 10;

	UPROPERTY(EditDefaultsOnly, Category = "Inventory Properties")
	TArray<FActorItemInfo> Inventory;
};
