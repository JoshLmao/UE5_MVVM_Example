#include "PartyWidget.h"

#include <Components/TextBlock.h>

#include "Components/ListView.h"
#include "UE5_MVVM_Example/UI/MVVM/ViewModel/VM_PartyPlayers.h"

UPartyWidget::UPartyWidget()
{
	ViewModelClass = UVM_PartyPlayers::StaticClass();
	ViewModelName = TEXT("VM_PartyPlayers");
}

void UPartyWidget::NativeConstruct()
{
	Super::NativeConstruct();

	const auto VMInst = TryGetViewModel<UVM_PartyPlayers>();
	checkf(IsValid(VMInst), TEXT("Couldn't find a valid ViewModel"));
	VMInst->AddFieldValueChangedDelegate(UVM_PartyPlayers::FFieldNotificationClassDescriptor::Status, FFieldValueChangedDelegate::CreateUObject(this, &ThisClass::VM_FieldChanged_Status));
	VMInst->AddFieldValueChangedDelegate(UVM_PartyPlayers::FFieldNotificationClassDescriptor::Players, FFieldValueChangedDelegate::CreateUObject(this, &ThisClass::VM_FieldChanged_Players));
}

void UPartyWidget::VM_FieldChanged_Status(UObject* Object, UE::FieldNotification::FFieldId FieldId)
{
	const auto VMInstance = Cast<UVM_PartyPlayers>(Object);
	StatusTextBlock->SetText(VMInstance->GetStatus() == EPartyStatus::Ready ? FText::FromString("Ready") : FText::FromString(("Not ready!")));
}

void UPartyWidget::VM_FieldChanged_Players(UObject* Object, UE::FieldNotification::FFieldId FieldId)
{
	const auto VMInstance = Cast<UVM_PartyPlayers>(Object);
	PartyListView->SetListItems(VMInstance->GetPlayers());
}
