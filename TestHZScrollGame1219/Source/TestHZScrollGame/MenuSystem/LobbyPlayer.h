// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LobbyPlayer.generated.h"

/**
 * 
 */
UCLASS()
class TESTHZSCROLLGAME_API ULobbyPlayer : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual bool Initialize();

public:
	UPROPERTY(meta = (BindWidget))
	class UImage* BackgroundImage;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* PlayerIndex;
};
