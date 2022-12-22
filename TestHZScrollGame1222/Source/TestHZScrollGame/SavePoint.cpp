// Fill out your copyright notice in the Description page of Project Settings.


#include "SavePoint.h"
#include "Components/BoxComponent.h"

// Sets default values
ASavePoint::ASavePoint()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TriggerVolume = CreateDefaultSubobject<UBoxComponent>(FName("TriggerVolume"));
	if (!ensure(TriggerVolume != nullptr)) return;

	RootComponent = TriggerVolume;

	TriggerVolume->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnOverlapBegin);
}

// Called when the game starts or when spawned
void ASavePoint::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ASavePoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASavePoint::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!bOverlapPlayer)
	{
		bOverlapPlayer = true;

		for (auto Iter = GetWorld()->GetPlayerControllerIterator(); Iter; ++Iter) {
			APlayerController* PlayerController = Iter->Get();
			PlayerController->GetPawn()->SetActorLocation(GetActorLocation());
		}
	}

	bOverlapPlayer = false;
}

