// Fill out your copyright notice in the Description page of Project Settings.


#include "TestHZScrollGamePlayerController.h"
#include "TestHZScrollGamePlayerState.h"
#include "TestHZScrollGameCharacter.h"
#include "TestHZScrollGameInstance.h"
#include "TestHZScrollGameStateBase.h"
#include "MenuSystem/MenuBase.h"
#include "MenuSystem/LobbyMenu.h"

void ATestHZScrollGamePlayerController::ServerSetPlayerNum_Implementation(int32 Value)
{
	ATestHZScrollGameStateBase* GameState = Cast<ATestHZScrollGameStateBase>(GetWorld()->GetGameState());
	if (GameState)
	{
		GameState->SetPlayerNum(Value);
	}
}

void ATestHZScrollGamePlayerController::ServerAddPlayerReady_Implementation()
{
	ATestHZScrollGameStateBase* GameState = Cast<ATestHZScrollGameStateBase>(GetWorld()->GetGameState());
	if (GameState)
	{
		GameState->AddPlayersReady();
	}
}

void ATestHZScrollGamePlayerController::ServerMinusPlayerReady_Implementation()
{
	ATestHZScrollGameStateBase* GameState = Cast<ATestHZScrollGameStateBase>(GetWorld()->GetGameState());
	if (GameState)
	{
		GameState->MinusPlayersReady();
	}
}

void ATestHZScrollGamePlayerController::ServerTravelLevel_Implementation(const FString& Address)
{
	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	auto GameInstance = Cast<UTestHZScrollGameInstance>(World->GetGameInstance());
	if (!ensure(GameInstance != nullptr)) return;
	
	GameInstance->TravelLevel(Address);
}

