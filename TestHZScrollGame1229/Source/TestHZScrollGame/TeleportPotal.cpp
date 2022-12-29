// Fill out your copyright notice in the Description page of Project Settings.


#include "TeleportPotal.h"
#include "Components/BoxComponent.h"

// Sets default values
ATeleportPotal::ATeleportPotal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	TriggerVolume = CreateDefaultSubobject<UBoxComponent>(FName("TriggerVolume"));
	if (!ensure(TriggerVolume != nullptr)) return;

	RootComponent = TriggerVolume;

	TriggerVolume->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnOverlapBegin);
}

// Called when the game starts or when spawned
void ATeleportPotal::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATeleportPotal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATeleportPotal::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	bOverlapPlayer = true;
	OtherActor->SetActorLocation(TargetLocationActor->GetActorLocation());
}