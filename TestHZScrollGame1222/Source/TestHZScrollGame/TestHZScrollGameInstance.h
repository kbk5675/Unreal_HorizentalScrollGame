// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MenuSystem/MenuInterface.h"
#include "TestHZScrollGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class TESTHZSCROLLGAME_API UTestHZScrollGameInstance : public UGameInstance, public IMenuInterface
{
	GENERATED_BODY()

public:
	UTestHZScrollGameInstance(const FObjectInitializer& ObjectInitializer);
	virtual void Init() override;

public:
	UFUNCTION(Exec)
	void Host();
	
	UFUNCTION(Exec)
	void Join(const FString& Address);

	UFUNCTION(Exec)
	void TravelStage1();

	UFUNCTION(Exec, BlueprintCallable)
	void LoadMainMenu();

	UFUNCTION(Exec, BlueprintCallable)
	void LoadLobbyMenu();

	UFUNCTION(Exec, BlueprintCallable)
	void LoadInGameMenu();

	UFUNCTION(Exec, BlueprintCallable)
	void LoadGameOverMenu();

	virtual void LoadMainMenuInGame() override;
	void LoadStage2();

public:
	UPROPERTY()
		TSubclassOf<class UUserWidget> MainMenuClass;

	UPROPERTY()
		TSubclassOf<class UUserWidget> LobbyMenuClass;

	UPROPERTY()
		TSubclassOf<class UUserWidget> InGameMenuClass;

	UPROPERTY()
		TSubclassOf<class UUserWidget> GameOverMenuClass;

public:
	class UMenuBase* MainMenu;
	class UMenuBase* InGameMenu;
	class UMenuBase* GameOverMenu;
	class UMenuBase* LobbyMenu;
};
