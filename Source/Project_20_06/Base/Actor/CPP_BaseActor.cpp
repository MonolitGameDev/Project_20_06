// Fill out your copyright notice in the Description page of Project Settings.


#include "Base/Actor/CPP_BaseActor.h"

ACPP_BaseActor::ACPP_BaseActor()
{
	//Collapse into a method
	PrimaryActorTick.bCanEverTick = false;
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	check(Root);

	RootComponent = Root;
}

