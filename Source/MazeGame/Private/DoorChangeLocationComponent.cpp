// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorChangeLocationComponent.h"

// Sets default values for this component's properties
UDoorChangeLocationComponent::UDoorChangeLocationComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDoorChangeLocationComponent::BeginPlay()
{
	Super::BeginPlay();
	//StartLocation = GetOwner()->GetActorLocation().GetComponentForAxis();
	// ...
	
}


// Called every frame
void UDoorChangeLocationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

