// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DoorInteractionComponent.generated.h"

class ATriggerBox;

UENUM()
enum class DoorType
{
	Normal,
	TimedVertical,
	Locked,
	ConstZRotation
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MAZEGAME_API UDoorInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDoorInteractionComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	void Translate(float DeltaTime);
	void ConstTranslate();

	UPROPERTY(EditAnywhere)
	DoorType Type;

	UPROPERTY(EditAnywhere)
	bool IsLocked = false;

	UPROPERTY(EditAnywhere)
	FRotator DesiredRotation = FRotator::ZeroRotator;
	FRotator StartRotation = FRotator::ZeroRotator;
	FRotator FinalRotation = FRotator::ZeroRotator;

	FVector StartLocation = FVector::ZeroVector;
	FVector FinalLocation = FVector::ZeroVector;

	UPROPERTY(EditAnywhere)
	float TimeToTransform = 1.0f; 
	float CurrentTransformTime = 0.0f;

	UPROPERTY(EditAnywhere)
	float TargetX;
	UPROPERTY(EditAnywhere)
	float TargetY;
	UPROPERTY(EditAnywhere)
	float TargetZ;

	UPROPERTY(EditAnywhere)
	TObjectPtr<ATriggerBox> TriggerBox;

	APawn* PlayerPawn;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
