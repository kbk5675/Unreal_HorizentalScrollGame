// Fill out your copyright notice in the Description page of Project Settings.


#include "TestHZScrollGameInstance.h"
#include "MenuSystem/MainMenu.h"
#include "MenuSystem/MenuBase.h"
#include "MenuSystem/LobbyMenu.h"
#include "MenuSystem/GameOverMenu.h"

UTestHZScrollGameInstance::UTestHZScrollGameInstance(const FObjectInitializer& ObjectInitializer)
{
	UE_LOG(LogTemp, Warning, TEXT("UTestHZScrollGameInstance"));
	// MainMenu
	ConstructorHelpers::FClassFinder<UUserWidget>MainMenuBPClass(TEXT("/Game/MenuSystem/Blueprint/WBP_MainMenu"));
	if (MainMenuBPClass.Succeeded())
	{
		MainMenuClass = MainMenuBPClass.Class;
	}

	// LobbyMenu
	ConstructorHelpers::FClassFinder<UUserWidget>LobbyMenuBPClass(TEXT("/Game/MenuSystem/Blueprint/WBP_LobbyMenu"));
	if (LobbyMenuBPClass.Succeeded())
	{
		LobbyMenuClass = LobbyMenuBPClass.Class;
	}

	// InGameMenu
	ConstructorHelpers::FClassFinder<UUserWidget>InGameMenuBPClass(TEXT("/Game/MenuSystem/Blueprint/WBP_InGameMenu"));
	if (InGameMenuBPClass.Succeeded())
	{
		InGameMenuClass = InGameMenuBPClass.Class;
	}

	// InGameMenu
	ConstructorHelpers::FClassFinder<UUserWidget>InGameUIBPClass(TEXT("/Game/MenuSystem/Blueprint/WBP_InGameUI"));
	if (InGameUIBPClass.Succeeded())
	{
		InGameUIClass = InGameUIBPClass.Class;
	}
	
	// GameOverMenu
	ConstructorHelpers::FClassFinder<UUserWidget>GameOverMenuBPClass(TEXT("/Game/MenuSystem/Blueprint/WBP_GameOverMenu"));
	if (GameOverMenuBPClass.Succeeded())
	{
		GameOverMenuClass = GameOverMenuBPClass.Class;
	}
}

void UTestHZScrollGameInstance::Init()
{

}

void UTestHZScrollGameInstance::Host()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Hosting"));
	}

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;
	World->ServerTravel("/Game/Maps/Lobby?listen");
}

void UTestHZScrollGameInstance::Join(const FString& Address)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Joining %s"), *Address));
	}

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
}

void UTestHZScrollGameInstance::TravelLevel(FString LevelAddress)
{
	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;
	World->ServerTravel(LevelAddress);
}

void UTestHZScrollGameInstance::LoadMainMenu()
{
	if (!ensure(MainMenuClass != nullptr)) return;
	MainMenu = CreateWidget<UMenuBase>(this, MainMenuClass);
	if (!ensure(MainMenu != nullptr)) return;

	MainMenu->SetUp_UIOnly();
	MainMenu->SetMenuInterface(this);
}

void UTestHZScrollGameInstance::LoadInGameMenu()
{
	if (!ensure(InGameMenuClass != nullptr)) return;
	InGameMenu = CreateWidget<UMenuBase>(this, InGameMenuClass);
	if (!ensure(InGameMenu!= nullptr)) return;

	InGameMenu->SetUp_UIOnly();
	InGameMenu->SetMenuInterface(this);
}

void UTestHZScrollGameInstance::LoadInGameUI()
{
	if (!ensure(InGameUIClass != nullptr)) return;
	InGameUI = CreateWidget<UMenuBase>(this, InGameUIClass);
	if (!ensure(InGameUI != nullptr)) return;

	InGameUI->SetUp_GameAndUI();
	InGameUI->SetMenuInterface(this);
}

void UTestHZScrollGameInstance::LoadLobbyMenu()
{
	if (!ensure(LobbyMenuClass != nullptr)) return;
	LobbyMenu = CreateWidget<UMenuBase>(this, LobbyMenuClass);
	if (!ensure(LobbyMenu != nullptr)) return;

	LobbyMenu->SetUp_GameAndUI();
	LobbyMenu->SetMenuInterface(this);
}

void UTestHZScrollGameInstance::LoadGameOverMenu()
{
	if (!ensure(GameOverMenuClass != nullptr)) return;
	GameOverMenu = CreateWidget<UMenuBase>(this, GameOverMenuClass);
	if (!ensure(GameOverMenu != nullptr)) return;

	GameOverMenu->SetUp_UIOnly();
	GameOverMenu->SetMenuInterface(this);
}

void UTestHZScrollGameInstance::LoadMainMenuInGame()
{
	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	PlayerController->ClientTravel("/Game/Maps/MainMenu?listen", ETravelType::TRAVEL_Absolute);
}
