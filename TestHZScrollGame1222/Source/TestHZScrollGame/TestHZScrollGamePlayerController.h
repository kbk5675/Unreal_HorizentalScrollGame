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

	UFUNCTION(NetMulticast, Reliable)
	void NetMulticastSetPlayerNum(int32 Value);


	UFUNCTION(Server, Reliable)
	void ServerAddPlayerReady();
	
	UFUNCTION(Server, Reliable)
	void ServerMinusPlayerReady();

	UFUNCTION(Server, Reliable)
	void NetMulticastAddPlayerReady();

	UFUNCTION(Server, Reliable)
	void NetMulticastMinusPlayerReady();


	UFUNCTION(Server, Reliable)
	void ServerPlayerWidgetSetGreen();

	UFUNCTION(Server, Reliable)
	void ServerPlayerWidgetSetRed();

	UFUNCTION(NetMulticast, Reliable)
	void NetMulticastPlayerWidgetSetGreen();

	UFUNCTION(NetMulticast, Reliable)
	void NetMulticastPlayerWidgetSetRed();

	UFUNCTION()
		bool bAllPlayersReady();
};
