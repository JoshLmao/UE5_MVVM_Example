#include "UE5_MVVM_Example/UI/Widget/MainMenuWidget.h"

#include "MVVMGameSubsystem.h"
#include "UE5_MVVM_Example/UI/MVVM/ViewModel/VM_PlayerHealth.h"
#include "View/MVVMView.h"
#include "View/MVVMViewClass.h"

void UMainMenuWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	// const auto MVVMCollection = GetWorld()->GetSubsystem<UMVVMGameSubsystem>()->GetViewModelCollection();
	// FMVVMViewModelContext Context;
	// Context.ContextClass = UVM_PlayerHealth::StaticClass();
	// Context.ContextName = TEXT("UVM_PlayerHealth");
	//MVVMCollection->AddViewModelInstance(Context);
}

void UMainMenuWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	// const auto ViewExtension = AddExtension(UMVVMView::StaticClass());
	//
	// FMVVMViewClass_Binding Binding;
	// auto thing = Binding.GetBinding();
	
	//const auto Collection = GetGameInstance()->GetSubsystem<UMVVMGameSubsystem>()->GetViewModelCollection();
}

void UMainMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	const auto VMInst = TryGetVM();
	const auto health = VMInst->GetCurrentHealth();
	UE_LOG(LogTemp, Log, TEXT("Health = %d"), health);
}

UVM_PlayerHealth* UMainMenuWidget::TryGetVM()
{
	const auto Collection = GetGameInstance()->GetSubsystem<UMVVMGameSubsystem>()->GetViewModelCollection();
	
	FMVVMViewModelContext Context;
	Context.ContextClass = UVM_PlayerHealth::StaticClass();
	Context.ContextName = TEXT("VM_PlayerHealth");
	const auto VMInstance = Collection->FindViewModelInstance(Context);
	if (IsValid(VMInstance))
	{
		return Cast<UVM_PlayerHealth>(VMInstance);
	}
	return nullptr;
}
