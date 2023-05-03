// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ArcherPlayerController.generated.h"

class AArcherCameraActor;
class AArcherPlayerCharacter;

/**
 * 
 */
UCLASS()
class ARCHER_API AArcherPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AArcherPlayerController();

	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

private:
	void MoveForward(float Input);
	
	void MoveRight(float Input);

	UPROPERTY(Transient, VisibleInstanceOnly)
	AArcherPlayerCharacter* PlayerCharacter{nullptr};
	
	UPROPERTY(Transient, VisibleInstanceOnly)
	AArcherCameraActor* CameraActor{nullptr};
};
