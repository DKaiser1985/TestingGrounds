// Fill out your copyright notice in the Description page of Project Settings.

#include "TestingGrounds.h"
#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrolRoute.h" //TODO: Remove this Include



EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	//Get the Patrol Points from the PatrolingThirdPersonCharacter Class
	auto AIController = OwnerComp.GetAIOwner();
	auto ControlledPawn = AIController->GetPawn();
	auto PatrolRoute = ControlledPawn->FindComponentByClass<UPatrolRoute>();

	//Protect Missing Control Route Component
	if (!ensure(PatrolRoute)){ return EBTNodeResult::Failed;}
	
	//Protect against Empty Patrol Array
	auto PatrolPoints = PatrolRoute->GetPatrolPoints();
	if (PatrolPoints.Num() == 0) { UE_LOG(LogTemp, Warning, TEXT("No Patrol Points on guard")); return EBTNodeResult::Failed;}

	//Set The Next Waypoint
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);

	//Cycle Next Patrol Point
	auto NextIndex = (Index + 1) % PatrolPoints.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);
	//Index = NextIndex;




	return EBTNodeResult::Succeeded;	
}
