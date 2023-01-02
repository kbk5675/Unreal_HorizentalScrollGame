// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TestHZScrollGamePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TESTHZSCROLLGAME_API ATestHZScrollGamePlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	UFUNCTION(Server, Reliable)
	void ServerSetPlayerNum(int32 Value);

	UFUNCTION(Server, Reliable)
	void ServerAddPlayerReady();
	
	UFUNCTION(Server, Reliable)
	void ServerMinusPlayerReady();

	UFUNCTION(Server, Reliable)
	void ServerTravelLevel(const FString& Address);
};
