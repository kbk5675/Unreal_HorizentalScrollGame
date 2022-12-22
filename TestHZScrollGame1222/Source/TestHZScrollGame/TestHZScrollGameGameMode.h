// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TestHZScrollGameGameMode.generated.h"

UCLASS(minimalapi)
class ATestHZScrollGameGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATestHZScrollGameGameMode();

	virtual void PostLogin(APlayerController* NewPlayer) override;
	virtual void Logout(AController* Exiting) override;
};



