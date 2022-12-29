// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuBase.h"
#include "InGameMenu.generated.h"

/**
 * 
 */
UCLASS()
class TESTHZSCROLLGAME_API UInGameMenu : public UMenuBase
{
	GENERATED_BODY()
	
protected:
	virtual bool Initialize() override;

private:
	UFUNCTION()
	void BackToGame();
	UFUNCTION()
	void BackToMainMenu();

private:
	UPROPERTY(meta = (BindWidget))
	class UButton* BtnCancel;

	UPROPERTY(meta = (BindWidget))
	class UButton* BtnQuit;
};
