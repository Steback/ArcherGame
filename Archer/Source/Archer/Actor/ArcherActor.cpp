// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/ArcherActor.h"

// Sets default values
AArcherActor::AArcherActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AArcherActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AArcherActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

