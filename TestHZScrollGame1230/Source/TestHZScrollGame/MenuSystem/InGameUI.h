// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuBase.h"
#include "InGameUI.generated.h"

/**
 * 
 */
UCLASS()
class TESTHZSCROLLGAME_API UInGameUI : public UMenuBase
{
	GENERATED_BODY()

protected:
	virtual bool Initialize() override;
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float DeltaTime) override;

	UFUNCTION()
	void StageCountdown();

	void CountingJump();

private:
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TimerText;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* JumpCntText;

	UPROPERTY(meta = (BindWidget))
	class UImage* Life0;

	UPROPERTY(meta = (BindWidget))
	class UImage* Life1;

	UPROPERTY(meta = (BindWidget))
	class UImage* Life2;

	UPROPERTY(VisibleAnywhere)
	TArray<class UImage*> TLife;

	UPROPERTY(Transient, meta = (BindWidgetAnim))
	class UWidgetAnimation* StartAnimation;

	FTimerHandle TimerHandle;
};
