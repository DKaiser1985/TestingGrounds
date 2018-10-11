// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "PatrolRoute.generated.h"


/**
*  A "route card" to help AI Choose their next Waypoint
*/
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTINGGROUNDS_API UPatrolRoute : public UActorComponent
{
	GENERATED_BODY()

public:	
	TArray<AActor*> UPatrolRoute::GetPatrolPoints() const;

private:	
	UPROPERTY(EditAnywhere, Category = "Patrol Route")
		TArray<AActor*> PatrolPoints;
};
