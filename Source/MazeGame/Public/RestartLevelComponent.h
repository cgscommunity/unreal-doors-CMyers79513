// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RestartLevelComponent.generated.h"

class ATriggerBox;

UENUM()
enum class ResetType
{
	ResetLevel,
	Respawn
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MAZEGAME_API URestartLevelComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URestartLevelComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere)
	FVector SpawnPoint;
	UPROPERTY(EditAnywhere)
	ResetType Type;
	UPROPERTY(EditAnywhere)
	TObjectPtr<ATriggerBox> TriggerBox;

	APawn* PlayerPawn;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
