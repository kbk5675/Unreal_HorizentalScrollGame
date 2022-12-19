// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuBase.h"
#include "LobbyMenu.generated.h"

/**
 * 
 */
UCLASS()
class TESTHZSCROLLGAME_API ULobbyMenu : public UMenuBase
{
	GENERATED_BODY()
	
protected:
	virtual bool Initialize() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float DeltaTime) override;

private:
	UFUNCTION()
	void PressedOnBtnReady();

	UFUNCTION()
	void PressedOnBtnCancel();

	void AddNewPlayer();

private:
	UPROPERTY(meta = (BindWidget))
	class UButton* BtnReady;

	UPROPERTY(meta = (BindWidget))
	class UButton* BtnCancel;

	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher* MenuSwitcher;

	UPROPERTY(meta = (BindWidget))
	class UWidget* WaitWidget;

	UPROPERTY(meta = (BindWidget))
	class UWidget* ReadyMenu;

	UPROPERTY(meta = (BindWidget))
	class UWidget* CancelMenu;

	UPROPERTY(meta = (BindWidget))
	class UHorizontalBox* PlayerStates;

	int32 PlayerNum = 0;
};
