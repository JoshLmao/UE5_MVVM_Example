#pragma once

#include <CoreMinimal.h>
#include "MVVMViewModelBase.h"
#include "VM_PlayerHealth.generated.h"

UCLASS()
class UVM_PlayerHealth : public UMVVMViewModelBase
{
	GENERATED_BODY()
	
public:
	void SetCurrentHealth(int32 InCurrentHealth)
	{
		if (UE_MVVM_SET_PROPERTY_VALUE(CurrentHealth, InCurrentHealth))
		{
			UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(GetHealthPercent);
		}
	}

	int32 GetCurrentHealth() const
	{
		return CurrentHealth;
	}
	
	void SetMaxHealth(int32 InMaxHealth)
	{
		if (UE_MVVM_SET_PROPERTY_VALUE(MaxHealth, InMaxHealth))
		{
			UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(GetHealthPercent);
		}
	}

	int32 GetMaxHealth() const
	{
		return MaxHealth;
	}
	
	UFUNCTION(BlueprintPure, FieldNotify)
	float GetHealthPercent() const
	{
		if (MaxHealth > 0)
		{
			return (float)CurrentHealth / (float)MaxHealth;
		}
		return 0;
	}
	
private:
	UPROPERTY(BlueprintReadOnly, FieldNotify, Getter, Setter, meta=(AllowPrivateAccess))
	int32 CurrentHealth = 0.f;

	UPROPERTY(BlueprintReadOnly, FieldNotify, Getter, Setter, meta=(AllowPrivateAccess))
	int32 MaxHealth = 0.f;
};