// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectReshape/Public/Items/Item2.h"
#include "DrawDebugHelpers.h"
#include "Common/DebugUtils.h"


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


	SetActorLocation(FVector(100.f, 100.f, 100.f));
	SetActorRotation(FRotator(180.f,180.f,30.f));
	
	DebugUtils::debugSphere(GetActorLocation(), GetWorld());
	DebugUtils::debugLine(GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 100.f, GetWorld());
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
