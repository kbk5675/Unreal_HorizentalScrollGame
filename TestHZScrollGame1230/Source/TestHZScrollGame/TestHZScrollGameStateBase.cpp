// Fill out your copyright notice in the Description page of Project Settings.


#include "TestHZScrollGameStateBase.h"
#include "TestHZScrollGamePlayerController.h"
#include "Net/UnrealNetwork.h"
#include "GameFramework/Actor.h"


ATestHZScrollGameStateBase::ATestHZScrollGameStateBase()
{
	PrimaryActorTick.bCanEverTick = true;
	UE_LOG(LogTemp, Warning, TEXT("ATestHZScrollGameStateBase"));
}

void ATestHZScrollGameStateBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ThisClass, PlayersNum);
	DOREPLIFETIME(ThisClass, PlayersReady);
	DOREPLIFETIME(ThisClass, Time);
}

void ATestHZScrollGameStateBase::UpdateServerTimeSeconds()
{
	Super::UpdateServerTimeSeconds();
}

bool ATestHZScrollGameStateBase::bAllPlayersReady()
{
	if (PlayersReady == GetWorld()->GetNumPlayerControllers())
	{
		return true;
	}
	else
	{
		return false;
	}
}