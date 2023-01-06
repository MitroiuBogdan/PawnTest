// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Bird.generated.h"

UCLASS()
class PROJECTRESHAPE_API ABird : public APawn
{
	GENERATED_BODY()

public:
	ABird();

private:
	UPROPERTY(VisibleAnywhere)
	class UCapsuleComponent* CapsuleComponent;
	UPROPERTY(VisibleAnywhere)
	class USkeletalMeshComponent* BirdMesh;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void MoveForward(float Value);

	virtual void MoveBackward(float Value);

	virtual void MoveRight(float Value);

	virtual void MoveLeft(float Value);
};
