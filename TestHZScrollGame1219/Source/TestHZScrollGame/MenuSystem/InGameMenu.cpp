// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameMenu.h"
#include "Components/Button.h"

bool UInGameMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	if (!ensure(BtnCancel != nullptr)) return false;
	if (!ensure(BtnQuit != nullptr)) return false;
	
	BtnCancel->OnClicked.AddDynamic(this, &ThisClass::BackToGame);
	BtnQuit->OnClicked.AddDynamic(this, &ThisClass::BackToMainMenu);

	return true;
}

void UInGameMenu::BackToGame()
{
	UE_LOG(LogTemp, Warning, TEXT("Pressed Cancel"));
	OnLevelRemovedFromWorld(GetWorld()->GetLevel(0), GetWorld());
}

void UInGameMenu::BackToMainMenu()
{
	if (MenuInterface != nullptr)
	{
		OnLevelRemovedFromWorld(GetWorld()->GetLevel(0), GetWorld());
		MenuInterface->LoadMainMenuInGame();
	}
}
