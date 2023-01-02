// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TestHZScrollGameCharacter.generated.h"

UCLASS(config=Game)
class ATestHZScrollGameCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Side view camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* SideViewCameraComponent;

	/** Camera boom positioning the camera beside the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

public:
	ATestHZScrollGameCharacter();

	FORCEINLINE class UCameraComponent* GetSideViewCameraComponent() const { return SideViewCameraComponent; }

	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	void ApplyName(const FString& Name);

	UFUNCTION(Server, Reliable)
	void ServerApplyName(const FString& Name);
	void ServerApplyName_Implementation(const FString& Name);
	
protected:

	/** Called for side to side input */
	void MoveRight(float Val);

	/** Handle touch inputs. */
	void TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location);

	/** Handle touch stop event. */
	void TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location);

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	void CountJump();

private:
	UFUNCTION()
	void OnRep_PlayerName();

//property
public:
	
protected:
	UPROPERTY(VisibleAnywhere, ReplicatedUsing = OnRep_PlayerName, Category = "PlayerStates")
	FString NickName;

private:
	UPROPERTY(EditInstanceOnly, Category = "NickName")
	class UTextRenderComponent* NameText;


};
