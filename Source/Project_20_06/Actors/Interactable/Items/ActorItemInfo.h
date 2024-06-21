// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerItemInfo.generated.h"

USTRUCT(BlueprintType)
struct PROJECT_20_06_API FActorItemInfo
{
public:

    GENERATED_BODY()

public:
    static FActorItemInfo CreateEmptyItemInfo(int32 Index);

public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Player Item Info")
    FString Name;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Player Item Info")
    TSubclassOf<class ACPP_Item> Class = nullptr;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Player Item Info")
    UTexture2D* Texture = nullptr;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Player Item Info")
    int32 Index;

public:
    bool operator==(const FActorItemInfo& Right) const;
};
