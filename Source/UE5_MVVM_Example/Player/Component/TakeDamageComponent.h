#pragma once

#include <CoreMinimal.h>
#include "TakeDamageComponent.generated.h"

UCLASS()
class UTakeDamageComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	void BeginPlay() override;

	void OnTakeDamageTick();
	
private:
	FTimerHandle TakeDamageHandle;
};