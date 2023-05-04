// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/ArcherPlayercharacter.h"

#include "Components/CapsuleComponent.h"
#include "GameFramework/FloatingPawnMovement.h"


AArcherPlayerCharacter::AArcherPlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	if (Capsule)
	{
		SetRootComponent(Capsule);
	}
	
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	if (Mesh)
	{
		Mesh->SetupAttachment(GetRootComponent());
	}

	Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement"));
}

void AArcherPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AArcherPlayerCharacter::Move(const FVector& Direction, float Input)
{
	if (Movement && Input != 0.0f)
	{
		SetActorRotation((Direction * Input).Rotation());
		AddMovementInput(Direction, Input);
	}
}
