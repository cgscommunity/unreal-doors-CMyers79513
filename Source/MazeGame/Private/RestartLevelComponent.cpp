// Fill out your copyright notice in the Description page of Project Settings.


#include "RestartLevelComponent.h"
#include "Engine/TriggerBox.h"
#include "Kismet/GameplayStatics.h"
// Sets default values for this component's properties
URestartLevelComponent::URestartLevelComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	Type = ResetType::Respawn;
}


// Called when the game starts
void URestartLevelComponent::BeginPlay()
{
	Super::BeginPlay();
	PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	SpawnPoint = FVector(1491.944746f, 3099.850312f, 98.337499f);
	
}


// Called every frame
void URestartLevelComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (TriggerBox && PlayerPawn)
	{
		if (TriggerBox->IsOverlappingActor(PlayerPawn))
		{
			switch (Type)
			{
				case ResetType::ResetLevel:
					UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
					break;
				case ResetType::Respawn:
					PlayerPawn->SetActorLocation(SpawnPoint);
					break;
			}
			
		}
		
	}
}

