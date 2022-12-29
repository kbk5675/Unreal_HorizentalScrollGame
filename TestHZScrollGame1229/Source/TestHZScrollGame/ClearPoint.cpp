// Fill out your copyright notice in the Description page of Project Settings.


#include "ClearPoint.h"
#include "TestHZScrollGamePlayerController.h"
#include "Components/BoxComponent.h"

// Sets default values
AClearPoint::AClearPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TriggerVolume = CreateDefaultSubobject<UBoxComponent>(FName("TriggerVolume"));
	if (!ensure(TriggerVolume != nullptr)) return;

	RootComponent = TriggerVolume;

	TriggerVolume->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnOverlapBegin);
}

// Called when the game starts or when spawned
void AClearPoint::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AClearPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AClearPoint::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	auto Controller = Cast<ATestHZScrollGamePlayerController>(World->GetFirstPlayerController());
	FString NextStage = "/Game/Maps/Lobby?listen";

	Controller->ServerTravelLevel(NextStage);

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("We going to next Stage!"));
	}
}