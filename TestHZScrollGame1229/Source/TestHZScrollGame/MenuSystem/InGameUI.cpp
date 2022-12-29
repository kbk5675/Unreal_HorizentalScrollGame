// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameUI.h"
#include "../TestHZScrollGameCharacter.h"
#include "../TestHZScrollGamePlayerController.h"
#include "../TestHZScrollGameInstance.h"
#include "../TestHZScrollGameStateBase.h"
#include "../TestHZScrollGamePlayerState.h"
#include "../TestHZScrollGameGameMode.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"

bool UInGameUI::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	Controller = Cast<ATestHZScrollGamePlayerController>(GetWorld()->GetFirstPlayerController());
	GameState = Cast<ATestHZScrollGameStateBase>(GetWorld()->GetGameState());
	GameInstance = Cast<UTestHZScrollGameInstance>(GetWorld()->GetGameInstance());

	if (!ensure(TimerText != nullptr)) return false;
	if (!ensure(JumpCntText != nullptr)) return false;
	if (!ensure(Life0 != nullptr)) return false;
	if (!ensure(Life1 != nullptr)) return false;
	if (!ensure(Life2 != nullptr)) return false;

	TLife.Empty();
	TLife.Add(Life0);
	TLife.Add(Life1);
	TLife.Add(Life2);

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return false;
	World->GetTimerManager().SetTimer(TimerHandle, this, &ThisClass::StageCountdown, 0.1f, true, 4.f);

	PlayAnimation(StartAnimation, 0.f, 1, EUMGSequencePlayMode::Forward);

	return true;
}

void UInGameUI::NativeConstruct()
{
	Super::NativeConstruct();
}

void UInGameUI::NativeTick(const FGeometry& MyGeometry, float DeltaTime)
{
	Super::NativeTick(MyGeometry, DeltaTime);

	PlayerState = Cast<ATestHZScrollGamePlayerState>(Controller->PlayerState);
	JumpCntText->SetText(FText::FromString(FString::Printf(TEXT("%d"),PlayerState->GetJumpCnt())));
}

void UInGameUI::StageCountdown()
{
	if (!ensure(GameState != nullptr)) return;

	TimerText->SetText(FText::FromString(FString::Printf(TEXT("%.1f"), GameState->GetTime())));

	GameState->CountDownTime(0.1f);

	if (GameState->GetTime() <= -0.1f)
	{
		GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
		this->RemoveFromViewport();

		GameInstance = Cast<UTestHZScrollGameInstance>(GetWorld()->GetGameInstance());
		GameInstance->LoadGameOverMenu();
	}
}



