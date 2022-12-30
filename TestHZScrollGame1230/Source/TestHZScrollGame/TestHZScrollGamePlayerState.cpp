// Fill out your copyright notice in the Description page of Project Settings.


#include "TestHZScrollGamePlayerState.h"
#include "TestHZScrollGameInstance.h"
#include "TestHZScrollGameCharacter.h"

ATestHZScrollGamePlayerState::ATestHZScrollGamePlayerState(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	UE_LOG(LogTemp, Warning, TEXT("ATestHZScrollGamePlayerState"));
	JumpCnt = 0;

}

void ATestHZScrollGamePlayerState::Reset()
{
	Super::Reset();

	auto GameInstance = Cast<UTestHZScrollGameInstance>(GetGameInstance());
	this->SetPlayerName(GameInstance->PlayerName);

	JumpCnt = 0;
}

void ATestHZScrollGamePlayerState::Destroyed()
{
}

void ATestHZScrollGamePlayerState::ClientInitialize(class AController* C)
{
	Super::ClientInitialize(C);
}

void ATestHZScrollGamePlayerState::CopyProperties(APlayerState* PlayerState)
{
	Super::CopyProperties(PlayerState);
	if (!ensure(PlayerState != nullptr)) return;
}

