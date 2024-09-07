#pragma once

#include <CoreMinimal.h>
#include <GameFramework/PlayerState.h>
#include "MyPlayerState.generated.h"

UCLASS()
class AMyPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	int32 GetCurrentHealth() { return CurrentHealth; };
	int32 GetMaxHealth() { return MaxHealth; };

	void SetCurrentHealth(int32 InHealth)
	{
		CurrentHealth = InHealth;
	}

	void SetMaxHealth(int32 InMaxHealth)
	{
		MaxHealth = InMaxHealth;
	}

private:
	int32 CurrentHealth = 0;
	int32 MaxHealth = 0;
};