// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuInterface.h"
#include "MenuBase.generated.h"

/**
 * 
 */
UCLASS()
class TESTHZSCROLLGAME_API UMenuBase : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld) override;

public:
	// Called automatically when leave the world
	void SetMenuInterface(IMenuInterface* Interface);

	// Contected viewport & Setting inputmode
	void SetUp_UIOnly();
	void SetUp_GameAndUI();

protected:
	IMenuInterface* MenuInterface;
};
