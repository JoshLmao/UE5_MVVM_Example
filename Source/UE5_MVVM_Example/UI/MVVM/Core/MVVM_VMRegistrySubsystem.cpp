#include "MVVM_VMRegistrySubsystem.h"

#include "MVVMGameSubsystem.h"
#include "MVVMViewModelBase.h"
#include "UE5_MVVM_Example/UI/MVVM/ViewModel/VM_PlayerHealth.h"

void UMVVM_VMRegistrySubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	Collection.InitializeDependency(UMVVMGameSubsystem::StaticClass());

	RegisterViewModels();
}

void UMVVM_VMRegistrySubsystem::RegisterViewModels()
{
	const auto MVVMCollection = GetGameInstance()->GetSubsystem<UMVVMGameSubsystem>()->GetViewModelCollection();
	
	AddViewModel(MVVMCollection, UVM_PlayerHealth::StaticClass(), FName("VM_PlayerHealth"));
}

void UMVVM_VMRegistrySubsystem::AddViewModel(UMVVMViewModelCollectionObject* VMCollection, const TSubclassOf<UMVVMViewModelBase>& ViewModelClass,
                                             FName ViewModelUniqueIdentifier)
{
	FMVVMViewModelContext ViewModelContext;
	ViewModelContext.ContextName = ViewModelUniqueIdentifier;
	ViewModelContext.ContextClass = ViewModelClass;

	const auto VMInstance = NewObject<UMVVMViewModelBase>(this, ViewModelClass);
	VMCollection->AddViewModelInstance(ViewModelContext, VMInstance);
}
