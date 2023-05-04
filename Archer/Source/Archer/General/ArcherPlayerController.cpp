// Fill out your copyright notice in the Description page of Project Settings.


#include "General/ArcherPlayerController.h"

#include "Actor/ArcherCameraActor.h"
#include "Character/ArcherPlayerCharacter.h"


AArcherPlayerController::AArcherPlayerController()
{
}

void AArcherPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	PlayerCharacter = Cast<AArcherPlayerCharacter>(GetPawn());
	CameraActor = GetWorld()->SpawnActor<AArcherCameraActor>(CameraActorTemplate);
	if (CameraActor)
	{
		SetViewTargetWithBlend(CameraActor);
	}
	
	if (CameraActor && PlayerCharacter)
	{
		CameraActor->SetTarget(PlayerCharacter);
	}
}

void AArcherPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	if (InputComponent)
	{
		InputComponent->BindAxis("MoveForward", this, &AArcherPlayerController::MoveForward);
		InputComponent->BindAxis("MoveRight", this, &AArcherPlayerController::MoveRight);
	}
}

void AArcherPlayerController::MoveForward(float Input)
{
	if (PlayerCharacter)
	{
		PlayerCharacter->Move(FVector::XAxisVector, Input);
		if (CameraActor)
		{
			CameraActor->Update();
		}
	}
}

void AArcherPlayerController::MoveRight(float Input)
{
	if (PlayerCharacter)
	{
		PlayerCharacter->Move(FVector::YAxisVector, Input);
		if (CameraActor)
		{
			CameraActor->Update();
		}
	}
}
