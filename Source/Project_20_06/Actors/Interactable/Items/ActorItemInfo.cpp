// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Interactable/Items/ActorItemInfo.h"
#include "Actors/Interactable/Items/CPP_Item.h"

FActorItemInfo FActorItemInfo::CreateEmptyItemInfo(int32 Index)
{
	FActorItemInfo emptyItem;
	emptyItem.Index = Index;
	return emptyItem;
}

bool FActorItemInfo::operator==(const FActorItemInfo& Right) const
{
	return Class == Right.Class;
}
