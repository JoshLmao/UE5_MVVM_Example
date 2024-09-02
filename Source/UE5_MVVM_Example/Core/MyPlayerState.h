#pragma once

#include <CoreMinimal.h>
#include <GameFramework/PlayerState.h>
#include "MyPlayerState.generated.h"

UCLASS()
class AMyPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	float GetCurrentHealth() { return CurrentHealth; };
	float GetMaxHealth() { return MaxHealth; };

	void SetCurrentHealth(float InHealth)
	{
		CurrentHealth = InHealth;
	}

	void SetMaxHealth(float InMaxHealth)
	{
		MaxHealth = InMaxHealth;
	}

private:
	float CurrentHealth = 0.f;
	float MaxHealth = 0.f;
};