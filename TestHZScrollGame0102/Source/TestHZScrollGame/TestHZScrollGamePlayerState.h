// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "TestHZScrollGamePlayerState.generated.h"

/**
 * 
 */
UCLASS()
class TESTHZSCROLLGAME_API ATestHZScrollGamePlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:
	ATestHZScrollGamePlayerState(const FObjectInitializer& ObjectInitializer);
	virtual void Reset() override;
	virtual void Destroyed() override;
	virtual void ClientInitialize(class AController* C) override;
	virtual void CopyProperties(APlayerState* PlayerState) override;

	int32 GetJumpCnt() { return JumpCnt; }
	void IncreasedJumpCnt() { ++JumpCnt; }

private:
	int32	JumpCnt;
};
