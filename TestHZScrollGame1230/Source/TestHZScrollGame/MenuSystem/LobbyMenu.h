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
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float DeltaTime) override;

private:
	UFUNCTION()
	void PressedOnBtnFinish();

	UFUNCTION()
	void PressedOnBtnReady();

	UFUNCTION()
	void PressedOnBtnCancel();

	UFUNCTION()
	void PressedOnBtnStart();

public:
	void SetPlayerWidget(int32 Value);

private:
	UPROPERTY(meta = (BindWidget))
	class UButton* BtnFinish;

	UPROPERTY(meta = (BindWidget))
	class UButton* BtnReady;

	UPROPERTY(meta = (BindWidget))
	class UButton* BtnCancel;

	UPROPERTY(meta = (BindWidget))
	class UButton* BtnStart;

	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher* MenuSwitcher;

	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher* ScreenSwitcher;

	UPROPERTY(meta = (BindWidget))
	class UEditableTextBox* PlayerNameField;

	UPROPERTY(meta = (BindWidget))
	class UWidget* LobbyMenu;

	UPROPERTY(meta = (BindWidget))
	class UWidget* InputNameMenu;

	UPROPERTY(meta = (BindWidget))
	class UWidget* WaitWidget;

	UPROPERTY(meta = (BindWidget))
	class UWidget* ReadyMenu;

	UPROPERTY(meta = (BindWidget))
	class UWidget* CancelMenu;

	UPROPERTY(meta = (BindWidget))
	class UWidget* StartMenu;

	UPROPERTY(meta = (BindWidget))
	class UWidget* HostMenu;

	UPROPERTY(meta = (BindWidget))
	class UWidget* Player_1;

	UPROPERTY(meta = (BindWidget))
	class UWidget* Player_2;

	UPROPERTY(meta = (BindWidget))
	class UWidget* Player_3;

	UPROPERTY(meta = (BindWidget))
	class UWidget* Player_4;

	UPROPERTY(meta = (BindWidget))
	class UWidget* Player_5;

	UPROPERTY(meta = (BindWidget))
	class UImage* BackgroundImage_1;

	UPROPERTY(meta = (BindWidget))
	class UImage* BackgroundImage_2;

	UPROPERTY(meta = (BindWidget))
	class UImage* BackgroundImage_3;

	UPROPERTY(meta = (BindWidget))
	class UImage* BackgroundImage_4;

	UPROPERTY(meta = (BindWidget))
	class UImage* BackgroundImage_5;

	UPROPERTY(VisibleAnywhere)
	TArray<class UWidget*> TPlayers;

	UPROPERTY(VisibleAnywhere)
	TArray<class UImage*> TBackgroundImage;
};
