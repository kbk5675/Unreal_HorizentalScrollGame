// Fill out your copyright notice in the Description page of Project Settings.


#include "GameOverMenu.h"
#include "../TestHZScrollGamePlayerController.h"
#include "Components/Button.h"

bool UGameOverMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	float WaitTime = 3.f;
	GetWorld()->GetTimerManager().SetTimer(GameOverTimerHandle, this, &ThisClass::BackToLobby, 1.f, false, 1.f);

	PlayAnimation(StartAnimation, 0.f, 1, EUMGSequencePlayMode::Forward);

	return true;
}

void UGameOverMenu::BackToLobby()
{
	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	World->GetTimerManager().ClearTimer(GameOverTimerHandle);
	
	FString Lobby = "/Game/Maps/Lobby?listen";

	auto Controller = Cast<ATestHZScrollGamePlayerController>(World->GetFirstPlayerController());
	Controller->ServerTravelLevel(Lobby);
}
