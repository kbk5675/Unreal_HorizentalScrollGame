// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestHZScrollGameGameMode.h"
#include "TestHZScrollGameCharacter.h"
#include "TestHZScrollGamePlayerState.h"
#include "UObject/ConstructorHelpers.h"

ATestHZScrollGameGameMode::ATestHZScrollGameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ATestHZScrollGameGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
	
	auto PlayerState = Cast<ATestHZScrollGamePlayerState>(NewPlayer->PlayerState);
	if (!ensure(PlayerState != nullptr)) return;
}

void ATestHZScrollGameGameMode::Logout(AController* Exiting)
{
	Super::Logout(Exiting);

	ULocalPlayer* Player = GetWorld()->GetFirstLocalPlayerFromController();
}
