// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/ArcherPawn.h"

// Sets default values
AArcherPawn::AArcherPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AArcherPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AArcherPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AArcherPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

