// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "TestHZScrollGameStateBase.generated.h"

/**
 * 
 */
UCLASS()
class TESTHZSCROLLGAME_API ATestHZScrollGameStateBase : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const;

	int32	GetPlayerNum() { return PlayersNum; }
	void	SetPlayerNum(int32 Value) { PlayersNum = Value; }

	int32 GetPlayersReady() { return PlayersReady; }
	void  AddPlayersReady() { PlayersReady++; }
	void  MinusPlayersReady() { PlayersReady--; }

	bool bAllPlayersReady();

private:
	UPROPERTY(VisibleAnywhere, Replicated)
	int32 PlayersNum = 0;

	UPROPERTY(VisibleAnywhere, Replicated)
	int32 PlayersReady = 1;
};
