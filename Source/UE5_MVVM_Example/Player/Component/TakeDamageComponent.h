#pragma once

#include <CoreMinimal.h>
#include <Components/ActorComponent.h>
#include "TakeDamageComponent.generated.h"

UCLASS()
class UTakeDamageComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	void BeginPlay() override;

	void OnTakeDamageTick();

	void UpdateMaxHealth(int32 NewMaxHealth);
	void UpdateCurrentHealth(int32 NewCurrentHealth);

	class UVM_PlayerHealth* GetVMPlayerHealth();
private:
	FTimerHandle TakeDamageHandle;
};