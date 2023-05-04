// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/ArcherCameraActor.h"
#include "Character/ArcherPawn.h"


void AArcherCameraActor::Update()
{
	if (IsValid(Target))
	{
		if (!Direction.IsNormalized())
		{
			Direction.Normalize();
		}
		
		SetActorLocation(Target->GetActorLocation() + FVector{Direction.X, Direction.Y, 1} * Height);
		SetActorRotation((Target->GetActorLocation() - GetActorLocation()).Rotation());
	}
}

void AArcherCameraActor::SetTarget(AArcherPawn* InTarget)
{
	if (IsValid(InTarget))
	{
		Target = InTarget;
	}
}
