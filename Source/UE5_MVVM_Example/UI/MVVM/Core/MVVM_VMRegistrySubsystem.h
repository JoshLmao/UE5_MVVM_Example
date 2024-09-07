#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "MVVM_VMRegistrySubsystem.generated.h"

UCLASS()
class UE5_MVVM_EXAMPLE_API UMVVM_VMRegistrySubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	void Initialize(FSubsystemCollectionBase& Collection) override;

private:
	void RegisterViewModels();
	void AddViewModel(class UMVVMViewModelCollectionObject* VMCollection, const TSubclassOf<class UMVVMViewModelBase>& ViewModel, FName ViewModelUniqueIdentifier);
};
