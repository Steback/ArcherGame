// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "ArcherCameraActor.generated.h"

class AArcherPawn;

/**
 * 
 */
UCLASS()
class ARCHER_API AArcherCameraActor : public ACameraActor
{
	GENERATED_BODY()

public:
	void Update();

	UFUNCTION(BlueprintCallable)
	void SetTarget(AArcherPawn* Target);

	FORCEINLINE AArcherPawn* GetTarget() const { return Target; }

private:
	UPROPERTY(Transient, VisibleInstanceOnly, BlueprintReadOnly, meta=(AllowPrivateAccess="True"))
	AArcherPawn* Target;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Height{500.0f};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Direction{FVector::XAxisVector};
};
