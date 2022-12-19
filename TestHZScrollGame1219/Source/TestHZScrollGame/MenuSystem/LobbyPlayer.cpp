// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyPlayer.h"

bool ULobbyPlayer::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	if (!ensure(BackgroundImage != nullptr)) return false;
	if (!ensure(PlayerIndex != nullptr)) return false;
	
	return true;
}