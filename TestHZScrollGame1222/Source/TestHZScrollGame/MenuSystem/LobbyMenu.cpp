// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyMenu.h"
#include "../TestHZScrollGamePlayerController.h"
#include "../TestHZScrollGameInstance.h"
#include "../TestHZScrollGameStateBase.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "Components/WidgetSwitcher.h"

// 컴파일 타임
bool ULobbyMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	UE_LOG(LogTemp, Warning, TEXT("Initialize"));

	if (!ensure(BtnReady != nullptr)) return false;
	if (!ensure(BtnCancel != nullptr)) return false;
	if (!ensure(BtnStart != nullptr)) return false;
	if (!ensure(WaitWidget != nullptr)) return false;
	if (!ensure(ReadyMenu != nullptr)) return false;
	if (!ensure(CancelMenu != nullptr)) return false;
	if (!ensure(StartMenu != nullptr)) return false;
	if (!ensure(HostMenu != nullptr)) return false;
	if (!ensure(MenuSwitcher != nullptr)) return false;
	if (!ensure(BackgroundImage_1 != nullptr)) return false;
	if (!ensure(BackgroundImage_2 != nullptr)) return false;
	if (!ensure(BackgroundImage_3 != nullptr)) return false;
	if (!ensure(BackgroundImage_4 != nullptr)) return false;
	if (!ensure(BackgroundImage_5 != nullptr)) return false;

	BtnReady->OnClicked.AddDynamic(this, &ThisClass::PressedOnBtnReady);
	BtnCancel->OnClicked.AddDynamic(this, &ThisClass::PressedOnBtnCancel);
	BtnStart->OnClicked.AddDynamic(this, &ThisClass::PressedOnBtnStart);

	TPlayers.Empty();
	TPlayers.Add(Player_1);
	TPlayers.Add(Player_2);
	TPlayers.Add(Player_3);
	TPlayers.Add(Player_4);
	TPlayers.Add(Player_5);

	TBackgroundImage.Empty();
	TBackgroundImage.Add(BackgroundImage_1);
	TBackgroundImage.Add(BackgroundImage_2);
	TBackgroundImage.Add(BackgroundImage_3);
	TBackgroundImage.Add(BackgroundImage_4);
	TBackgroundImage.Add(BackgroundImage_5);

	Controller = Cast<ATestHZScrollGamePlayerController>(GetWorld()->GetFirstPlayerController());
	GameState = Cast<ATestHZScrollGameStateBase>(GetWorld()->GetGameState());
	return true; 
}

// 런타임
void ULobbyMenu::NativeConstruct()
{
	Super::NativeConstruct();
	UE_LOG(LogTemp, Warning, TEXT("NativeConstruct"));
}

void ULobbyMenu::NativeTick(const FGeometry& MyGeometry, float DeltaTime)
{
	Super::NativeTick(MyGeometry, DeltaTime);

	int32 CurrentPlayerNum = GetWorld()->GetNumPlayerControllers();

	if (Controller->HasAuthority())		
	{
		// Server
		if (CurrentPlayerNum != GameState->GetPlayerNum())
		{
			Controller->ServerSetPlayerNum(CurrentPlayerNum);
			AddNewPlayer(GameState->GetPlayerNum());
		}

		if (Controller->bAllPlayersReady())
		{
			WaitWidget->SetVisibility(ESlateVisibility::Hidden);
			MenuSwitcher->SetActiveWidget(StartMenu);
		}
		else
		{
			WaitWidget->SetVisibility(ESlateVisibility::Visible);
			MenuSwitcher->SetActiveWidget(HostMenu);
		}
	}
	else
	{
		// Client
		if (CurrentPlayerNum != GameState->GetPlayerNum())
		{
			AddNewPlayer(GameState->GetPlayerNum());
			UE_LOG(LogTemp, Warning, TEXT("%d"), GameState->GetPlayerNum());
		}
	}

	//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Purple, FString::Printf(TEXT("%d %d"), GameState->GetPlayerNum(), GameState->GetPlayersReady()));
}

void ULobbyMenu::PressedOnBtnReady()
{
	Controller->ServerPlayerWidgetSetGreen();

	Controller->ServerAddPlayerReady(); // Ready + 1

	WaitWidget->SetVisibility(ESlateVisibility::Visible);
	MenuSwitcher->SetActiveWidget(CancelMenu);

	BtnReady->SetIsEnabled(false);
	BtnCancel->SetIsEnabled(true);
}

void ULobbyMenu::PressedOnBtnCancel()
{
	Controller->ServerMinusPlayerReady();

	Controller->ServerPlayerWidgetSetRed();

	WaitWidget->SetVisibility(ESlateVisibility::Hidden);
	MenuSwitcher->SetActiveWidget(ReadyMenu);

	BtnCancel->SetIsEnabled(false);
	BtnReady->SetIsEnabled(true);
}

void ULobbyMenu::PressedOnBtnStart()
{
	auto GameInstance = Cast<UTestHZScrollGameInstance>(GetWorld()->GetGameInstance());
	if (!ensure(GameInstance != nullptr)) return;
	
	GameInstance->TravelStage1();
}

void ULobbyMenu::AddNewPlayer(int32 Value)
{
	for (int32 i = 0; i < TPlayers.Num(); i++)
	{
		TPlayers[i]->SetVisibility(ESlateVisibility::Hidden);
	}

	for (int32 i = 0; i < Value; i++)
	{
		TPlayers[i]->SetVisibility(ESlateVisibility::Visible);
	}
}

void ULobbyMenu::PlayerWidgetSetGreen()
{
	FLinearColor Green = FLinearColor(0.f, 1.f, 0.18f, 1.f);
	TBackgroundImage[GameState->GetPlayersReady()]->SetColorAndOpacity(Green);
}

void ULobbyMenu::PlayerWidgetSetRed()
{
	// Image Set Red
	FLinearColor Red = FLinearColor(1.f, 0.15f, 0.07f, 1.f);
	TBackgroundImage[GameState->GetPlayersReady()]->SetColorAndOpacity(Red);
}

