// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuBase.h"
#include "GameOverMenu.generated.h"

/**
 * 
 */
UCLASS()
class TESTHZSCROLLGAME_API UGameOverMenu : public UMenuBase
{
	GENERATED_BODY()
	
protected:
	virtual bool Initialize() override;

	UPROPERTY(Transient, meta = (BindWidgetAnim))
	class UWidgetAnimation* StartAnimation;

	void BackToLobby();

private:
	FTimerHandle GameOverTimerHandle;
};
