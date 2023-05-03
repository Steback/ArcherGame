// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/ArcherPawn.h"
#include "ArcherPlayercharacter.generated.h"

/**
 * 
 */
UCLASS()
class ARCHER_API AArcherPlayerCharacter : public AArcherPawn
{
	GENERATED_BODY()

public:
	AArcherPlayerCharacter();

	virtual void BeginPlay() override;;

	void Move(const FVector& Direction, float Input);
	
	FORCEINLINE class USkeletalMeshComponent* GetMesh() const { return Mesh; }
	
	FORCEINLINE class UCapsuleComponent* GetCapsule() const { return Capsule; }

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(AllowPrivateAccess="True"))
	UCapsuleComponent* Capsule;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(AllowPrivateAccess="True"))
	USkeletalMeshComponent* Mesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess="True"))
	class UFloatingPawnMovement* Movement;
};
