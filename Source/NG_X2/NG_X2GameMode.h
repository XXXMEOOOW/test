// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "NG_X2GameMode.generated.h"

/**
 *  Simple GameMode for a third person game
 */
UCLASS(abstract)
class ANG_X2GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	
	/** Constructor */
	ANG_X2GameMode();
};



