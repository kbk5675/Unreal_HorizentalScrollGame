// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyMenu.h"
#include "LobbyPlayer.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/HorizontalBox.h"

bool ULobbyMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	if (!ensure(BtnReady != nullptr)) return false;
	if (!ensure(BtnCancel != nullptr)) return false;
	if (!ensure(WaitWidget != nullptr)) return false;
	if (!ensure(ReadyMenu != nullptr)) return false;
	if (!ensure(CancelMenu != nullptr)) return false;
	if (!ensure(MenuSwitcher != nullptr)) return false;
	if (!ensure(PlayerStates != nullptr)) return false;

	BtnReady->OnClicked.AddDynamic(this, &ThisClass::PressedOnBtnReady);
	BtnCancel->OnClicked.AddDynamic(this, &ThisClass::PressedOnBtnCancel);

	return true;
}

void ULobbyMenu::NativeTick(const FGeometry& MyGeometry, float DeltaTime)
{
	Super::NativeTick(MyGeometry, DeltaTime);
	
	PlayerNum = GetWorld()->GetPlayerControllerIterator().GetIndex();
}

void ULobbyMenu::PressedOnBtnReady()
{
	WaitWidget->SetVisibility(ESlateVisibility::Visible);
	MenuSwitcher->SetActiveWidget(CancelMenu);
}

void ULobbyMenu::PressedOnBtnCancel()
{
	WaitWidget->SetVisibility(ESlateVisibility::Hidden);
	MenuSwitcher->SetActiveWidget(ReadyMenu);
}

void ULobbyMenu::AddNewPlayer()
{
	

	for (int32 i = 0; i < PlayerNum; i++)
	{
		//PlayerStates->AddChildToHorizontalBox();
	}
}

