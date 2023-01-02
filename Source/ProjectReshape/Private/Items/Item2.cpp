// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectReshape/Public/Items/Item2.h"

// Sets default values
AItem2::AItem2()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AItem2::BeginPlay()
{
	Super::BeginPlay();
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Blue, FString("Hello from debug"));
	}
}

// Called every frame
void AItem2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GEngine)
	{
		FString message = FString::Printf(TEXT("dt -> %f"), DeltaTime);
		GEngine->AddOnScreenDebugMessage(2, 60.f, FColor::Blue, message);
	}
}
