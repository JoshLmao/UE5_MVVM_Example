#include "UE5_MVVM_Example/UI/Widget/MainMenuWidget.h"

#include "MVVMGameSubsystem.h"
#include "Components/ProgressBar.h"
#include "UE5_MVVM_Example/UI/MVVM/ViewModel/VM_PlayerHealth.h"
#include "View/MVVMView.h"
#include "View/MVVMViewClass.h"

void UMainMenuWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UMainMenuWidget::NativePreConstruct()
{
	Super::NativePreConstruct();
}

void UMainMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	const auto VMInst = TryGetVM();
	const auto health = VMInst->GetCurrentHealth();
	UE_LOG(LogTemp, Log, TEXT("Health = %d"), health);

	VMInst->AddFieldValueChangedDelegate(UVM_PlayerHealth::FFieldNotificationClassDescriptor::CurrentHealth, INotifyFieldValueChanged::FFieldValueChangedDelegate::CreateUObject(this, &UMainMenuWidget::OnFieldChanged));
}

void UMainMenuWidget::OnFieldChanged(UObject* Object, UE::FieldNotification::FFieldId FieldId)
{ 
	const auto VM = TryGetVM();
	UE_LOG(LogTemp, Log, TEXT("CurrentHealth changed - new percent '%f' - current/max = %d/%d"), VM->GetHealthPercent(), VM->GetCurrentHealth(), VM->GetMaxHealth());
	HealthProgressBar->SetPercent(VM->GetHealthPercent());
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
