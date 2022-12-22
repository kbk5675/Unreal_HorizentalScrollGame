// Fill out your copyright notice in the Description page of Project Settings.


#include "TestHZScrollGamePlayerController.h"
#include "TestHZScrollGameInstance.h"
#include "TestHZScrollGameStateBase.h"
#include "MenuSystem/MenuBase.h"
#include "MenuSystem/LobbyMenu.h"

void ATestHZScrollGamePlayerController::ServerSetPlayerNum_Implementation(int32 Value)
{
	NetMulticastSetPlayerNum(Value);
}

void ATestHZScrollGamePlayerController::NetMulticastSetPlayerNum_Implementation(int32 Value)
{
	ATestHZScrollGameStateBase* GameState = Cast<ATestHZScrollGameStateBase>(GetWorld()->GetGameState());
	if (GameState)
	{
		GameState->SetPlayerNum(Value);
	}
}


void ATestHZScrollGamePlayerController::ServerPlayerWidgetSetGreen_Implementation()
{
	NetMulticastPlayerWidgetSetGreen();
}

void ATestHZScrollGamePlayerController::ServerPlayerWidgetSetRed_Implementation()
{
	NetMulticastPlayerWidgetSetRed();
}

void ATestHZScrollGamePlayerController::NetMulticastPlayerWidgetSetGreen_Implementation()
{
	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	UGameInstance* GameInstance = World->GetGameInstance();
	if (!ensure(GameInstance != nullptr)) return;

	ULobbyMenu* Widget = Cast<ULobbyMenu>(Cast<UTestHZScrollGameInstance>(GameInstance)->LobbyMenu);
	if (Widget)
	{
		Widget->PlayerWidgetSetGreen();
	}
}

void ATestHZScrollGamePlayerController::NetMulticastPlayerWidgetSetRed_Implementation()
{
	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	UGameInstance* GameInstance = World->GetGameInstance();
	if (!ensure(GameInstance != nullptr)) return;

	ULobbyMenu* Widget = Cast<ULobbyMenu>(Cast<UTestHZScrollGameInstance>(GameInstance)->LobbyMenu);
	if (Widget)
	{
		Widget->PlayerWidgetSetRed();
	}
}


void ATestHZScrollGamePlayerController::ServerAddPlayerReady_Implementation()
{
	NetMulticastAddPlayerReady();
}

void ATestHZScrollGamePlayerController::ServerMinusPlayerReady_Implementation()
{
	NetMulticastMinusPlayerReady();
}

void ATestHZScrollGamePlayerController::NetMulticastAddPlayerReady_Implementation()
{
	ATestHZScrollGameStateBase* GameState = Cast<ATestHZScrollGameStateBase>(GetWorld()->GetGameState());
	if (GameState)
	{
		GameState->AddPlayersReady();
	}
}

void ATestHZScrollGamePlayerController::NetMulticastMinusPlayerReady_Implementation()
{
	ATestHZScrollGameStateBase* GameState = Cast<ATestHZScrollGameStateBase>(GetWorld()->GetGameState());
	if (GameState)
	{
		GameState->MinusPlayersReady();
	}
}



bool ATestHZScrollGamePlayerController::bAllPlayersReady()
{
	ATestHZScrollGameStateBase* GameState = Cast<ATestHZScrollGameStateBase>(GetWorld()->GetGameState());
	if (GameState)
	{
		return GameState->bAllPlayersReady();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Fail to Load GameState->AllPlayersReady"));
		return false;
	}

}

