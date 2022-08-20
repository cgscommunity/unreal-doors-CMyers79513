// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorInteractionComponent.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Engine/TriggerBox.h"
#include "Engine/World.h"
#include "Engine/Engine.h"

// Sets default values for this component's properties
UDoorInteractionComponent::UDoorInteractionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UDoorInteractionComponent::BeginPlay()
{
	Super::BeginPlay();
	PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	switch (Type){
		case DoorType::Normal:
			StartRotation = GetOwner()->GetActorRotation();
			FinalRotation = GetOwner()->GetActorRotation() + DesiredRotation;
			break;
		case DoorType::TimedVertical:
			StartLocation = GetOwner()->GetActorLocation();
			FinalLocation = FVector(StartLocation.Component(0), StartLocation.Component(1), TargetZ);
			break;
	}
}

void UDoorInteractionComponent::Translate(float DeltaTime)
{
	if (CurrentTransformTime == 0.0f && DeltaTime < 0 || CurrentTransformTime == TimeToTransform && DeltaTime > 0) return; 
	CurrentTransformTime = FMath::Clamp(CurrentTransformTime + DeltaTime, 0.0f, TimeToTransform);
	const float TransformAlpha = FMath::Clamp(CurrentTransformTime / TimeToTransform, 0.0f, 1.0f);
	switch (Type) {
		case DoorType::Normal:
		{
			const FRotator CurrentRotation = FMath::Lerp(StartRotation, FinalRotation, TransformAlpha);
			GetOwner()->SetActorRotation(CurrentRotation);
			break;
		}
		case DoorType::TimedVertical:
		{
			const FVector CurrentLocation = FMath::Lerp(StartLocation, FinalLocation, TransformAlpha);
			GetOwner()->SetActorLocation(CurrentLocation);
			break;
		}
		case DoorType::ConstZRotation:
			TargetZ = FMath::Fmod(TargetZ + 10.0, 360.0);
			GetOwner()->SetActorRotation(GetOwner()->GetActorRotation() + FRotator(0.0f,0.0f,10.0f));
			break;
	}
}

void UDoorInteractionComponent::ConstTranslate()
{
	switch (Type) {
	case DoorType::ConstZRotation:
		TargetZ = FMath::Fmod(TargetZ + 10.0, 360.0);
		GetOwner()->SetActorRotation(GetOwner()->GetActorRotation() + FRotator(0.0f, 0.0f, 10.0f));
		break;
	}
}

void UDoorInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	switch (Type) {
		case DoorType::Normal:
			if (TriggerBox && PlayerPawn)
			{
				if (TriggerBox->IsOverlappingActor(PlayerPawn) && !IsLocked)
				{
					Translate(DeltaTime);
				}
				else if (!TriggerBox->IsOverlappingActor(PlayerPawn) && !IsLocked)
				{
					Translate(-DeltaTime);
				}
			}
			break;
		case DoorType::TimedVertical:
			Translate(DeltaTime);
			break;
		case DoorType::ConstZRotation:
			ConstTranslate();
	}
}

