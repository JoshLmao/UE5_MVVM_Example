#include "UE5_MVVM_Example/UI/Widget/MainMenuWidget.h"

#include "Components/ProgressBar.h"
#include "UE5_MVVM_Example/UI/MVVM/ViewModel/VM_PlayerHealth.h"

UMainMenuWidget::UMainMenuWidget()
{
	ViewModelClass = UVM_PlayerHealth::StaticClass();
	ViewModelName = TEXT("VM_PlayerHealth");
}

void UMainMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	const auto VMInst = TryGetViewModel<UVM_PlayerHealth>();
	VMInst->AddFieldValueChangedDelegate(UVM_PlayerHealth::FFieldNotificationClassDescriptor::CurrentHealth, INotifyFieldValueChanged::FFieldValueChangedDelegate::CreateUObject(this, &UMainMenuWidget::OnFieldChanged));
}

void UMainMenuWidget::OnFieldChanged(UObject* Object, UE::FieldNotification::FFieldId FieldId)
{ 
	const auto VM = TryGetViewModel<UVM_PlayerHealth>();
	UE_LOG(LogTemp, Log, TEXT("CurrentHealth changed - new percent '%f' - current/max = %d/%d"), VM->GetHealthPercent(), VM->GetCurrentHealth(), VM->GetMaxHealth());
	HealthProgressBar->SetPercent(VM->GetHealthPercent());
}