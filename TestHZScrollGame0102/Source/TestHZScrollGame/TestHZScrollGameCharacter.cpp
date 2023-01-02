// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestHZScrollGameCharacter.h"
#include "TestHZScrollGamePlayerController.h"
#include "TestHZScrollGamePlayerState.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Components/TextRenderComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/NavMovementComponent.h"
#include "Net/UnrealNetwork.h"

ATestHZScrollGameCharacter::ATestHZScrollGameCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Create a camera boom attached to the root (capsule)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Rotation of the character should not affect rotation of boom
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->TargetArmLength = 500.f;
	CameraBoom->SocketOffset = FVector(0.f,0.f,75.f);
	CameraBoom->SetRelativeRotation(FRotator(0.f,180.f,0.f));

	// Create a camera and attach to boom
	SideViewCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
	SideViewCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	SideViewCameraComponent->bUsePawnControlRotation = false; // We don't want the controller rotating the camera

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Face in the direction we are moving..
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->GravityScale = 2.f;
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->JumpZVelocity = 1000.f;
	GetCharacterMovement()->GroundFriction = 3.f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MaxFlySpeed = 600.f;

	NameText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("NAMETEXT"));
	NameText->SetupAttachment(CameraBoom);
	NameText->SetHorizontalAlignment(EHorizTextAligment::EHTA_Center);
}

void ATestHZScrollGameCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ThisClass, NickName);
}

void ATestHZScrollGameCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// set up gameplay key bindings
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ThisClass::CountJump);

	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAxis("MoveRight", this, &ATestHZScrollGameCharacter::MoveRight);

	PlayerInputComponent->BindTouch(IE_Pressed, this, &ATestHZScrollGameCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &ATestHZScrollGameCharacter::TouchStopped);
}

void ATestHZScrollGameCharacter::CountJump()
{
	if (this->CanJump())
	{
		auto HZPlayerState = Cast<ATestHZScrollGamePlayerState>(GetPlayerState());
		if (!ensure(HZPlayerState != nullptr)) return;

		HZPlayerState->IncreasedJumpCnt();
	}
}

void ATestHZScrollGameCharacter::ApplyName(const FString& Name)
{
	NickName = Name;
	NameText->SetText(FText::FromString(NickName));
}

void ATestHZScrollGameCharacter::ServerApplyName_Implementation(const FString& Name)
{
	ApplyName(Name);
}

void ATestHZScrollGameCharacter::OnRep_PlayerName()
{
	ApplyName(NickName);
}

void ATestHZScrollGameCharacter::MoveRight(float Value)
{
	// add movement in that direction
	AddMovementInput(FVector(0.f,-1.f,0.f), Value);
}

void ATestHZScrollGameCharacter::TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	// jump on any touch
	Jump();
}

void ATestHZScrollGameCharacter::TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	StopJumping();
}