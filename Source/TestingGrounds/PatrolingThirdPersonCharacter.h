// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "PatrolingThirdPersonCharacter.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGGROUNDS_API APatrolingThirdPersonCharacter : public ATP_ThirdPersonCharacter
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, Category = "Patrol Route")
		TArray<AActor*> PatrolPointsCPP;
	
	
};
