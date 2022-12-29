// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StageClearTrigger.generated.h"

UCLASS()
class TESTHZSCROLLGAME_API AStageClearTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	AStageClearTrigger();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

private:

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(EditInstanceOnly)
	class UBoxComponent* TriggerVolume;

	bool bOverlapPlayer;

};
