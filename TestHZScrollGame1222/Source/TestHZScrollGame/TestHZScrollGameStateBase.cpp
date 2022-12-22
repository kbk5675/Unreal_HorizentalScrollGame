// Fill out your copyright notice in the Description page of Project Settings.


#include "TestHZScrollGameStateBase.h"
#include "TestHZScrollGamePlayerController.h"
#include "Net/UnrealNetwork.h"

void ATestHZScrollGameStateBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ThisClass, PlayersNum);
	DOREPLIFETIME(ThisClass, PlayersReady);
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
