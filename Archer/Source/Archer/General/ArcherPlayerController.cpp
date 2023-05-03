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
	CameraActor = GetWorld()->SpawnActor<AArcherCameraActor>();
	if (CameraActor)
	{
		SetViewTargetWithBlend(CameraActor);
	}
	
	if (CameraActor && PlayerCharacter)
	{
		CameraActor->SetActorLocation(PlayerCharacter->GetActorLocation() + (FVector::ZAxisVector * 500.0f));
		CameraActor->SetActorRotation((PlayerCharacter->GetActorLocation() - CameraActor->GetActorLocation()).Rotation());
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
		PlayerCharacter->Move(PlayerCharacter->GetActorForwardVector(), Input);
	}
}

void AArcherPlayerController::MoveRight(float Input)
{
	if (PlayerCharacter)
	{
		PlayerCharacter->Move(PlayerCharacter->GetActorRightVector(), Input);
	}
}
