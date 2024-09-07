#pragma once

#include "CoreMinimal.h"
#include <Blueprint/UserWidget.h>
#include <MVVMGameSubsystem.h>
#include <Types/MVVMViewModelContext.h>
#include "MyBaseUserWidget.generated.h"

UCLASS(Abstract)
class UE5_MVVM_EXAMPLE_API UMyBaseUserWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	template <typename VMClass>
	VMClass* TryGetViewModel() const
	{
		const auto Collection = GetGameInstance()->GetSubsystem<UMVVMGameSubsystem>()->GetViewModelCollection();
	
		FMVVMViewModelContext Context;
		Context.ContextClass = ViewModelClass;
		Context.ContextName = ViewModelName;
		const auto VMInstance = Collection->FindViewModelInstance(Context);
		if (IsValid(VMInstance))
		{
			return Cast<VMClass>(VMInstance);
		}
		checkf(false, TEXT("Unable to find a ViewModel that matches the given ViewModelName and ViewModelClass!"));
		return nullptr;
	}

protected:
	UPROPERTY(EditAnywhere)
	FName ViewModelName;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UMVVMViewModelBase> ViewModelClass;
};
