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

	UE_LOG(LogTemp, Warning, TEXT("Initialize"));

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

	auto Controller = Cast<ATestHZScrollGamePlayerController>(World->GetFirstPlayerController());
	if (!ensure(Controller != nullptr)) return false;

	auto GameInstance = Cast<UTestHZScrollGameInstance>(World->GetGameInstance());
	if (!ensure(GameInstance != nullptr)) return false;
	
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

	CountingJump();
}

void UInGameUI::StageCountdown()
{
	auto GameState = Cast<ATestHZScrollGameStateBase>(GetWorld()->GetGameState());
	if (!ensure(GameState != nullptr)) return;

	TimerText->SetText(FText::FromString(FString::Printf(TEXT("%.1f"), GameState->GetTime())));

	GameState->CountDownTime(0.1f);

	if (GameState->GetTime() <= -0.1f)
	{
		GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
		this->RemoveFromViewport();

		auto GameInstance = Cast<UTestHZScrollGameInstance>(GetGameInstance());
		if (!ensure(GameInstance != nullptr)) return;

		GameInstance->LoadGameOverMenu();
	}
}

void UInGameUI::CountingJump()
{
	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	auto Controller = Cast<ATestHZScrollGamePlayerController>(World->GetFirstPlayerController());
	if (!ensure(Controller != nullptr)) return;

	auto PlayerState = Cast<ATestHZScrollGamePlayerState>(Controller->PlayerState);
	if (!ensure(PlayerState != nullptr)) return;

	JumpCntText->SetText(FText::FromString(FString::Printf(TEXT("%d"), PlayerState->GetJumpCnt())));
}


