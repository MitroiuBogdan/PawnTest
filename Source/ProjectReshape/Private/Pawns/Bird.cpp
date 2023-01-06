// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/Bird.h"
#include "Components/CapsuleComponent.h"

ABird::ABird()
{
	PrimaryActorTick.bCanEverTick = true;
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsume"));
	BirdMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletonMesh"));

	SetRootComponent(CapsuleComponent);
	BirdMesh->SetupAttachment(GetRootComponent());

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

void ABird::BeginPlay()
{
	Super::BeginPlay();
}

void ABird::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABird::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MOVE_F"), this, &ABird::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MOVE_B"), this, &ABird::MoveBackward);
	PlayerInputComponent->BindAxis(TEXT("MOVE_L"), this, &ABird::MoveLeft);
	PlayerInputComponent->BindAxis(TEXT("MOVE_R"), this, &ABird::MoveRight);
}

void ABird::MoveForward(float Value)
{
	if (Controller && Value != 0)
	{
		FVector Forward = GetActorForwardVector();
		AddMovementInput(Forward, Value);
	}
	UE_LOG(LogTemp, Warning, TEXT("M_F - %f"), Value);
}

void ABird::MoveBackward(float Value)
{
	UE_LOG(LogTemp, Warning, TEXT("M_B - %f"), Value);
	if (Controller && Value != 0)
	{
		FVector Forward = GetActorForwardVector();
		AddMovementInput(Forward, -Value);
	}
}

void ABird::MoveRight(float Value)
{
	UE_LOG(LogTemp, Warning, TEXT("M_R - %f"), Value);
}

void ABird::MoveLeft(float Value)
{
	UE_LOG(LogTemp, Warning, TEXT("M_L - %f"), Value);
}
