#pragma once

#include "CoreMinimal.h"
#include "UE5_MVVM_Example/UI/Widget/Core/MyBaseUserWidget.h"
#include "PartyWidget.generated.h"

UCLASS(Abstract)
class UE5_MVVM_EXAMPLE_API UPartyWidget : public UMyBaseUserWidget
{
	GENERATED_BODY()

public:
	UPartyWidget();

protected:
	void NativeConstruct() override;

	void VM_FieldChanged_Status(UObject* Object, UE::FieldNotification::FFieldId FieldId);
	void VM_FieldChanged_Players(UObject* Object, UE::FieldNotification::FFieldId FieldId);
	
private:
	UPROPERTY(meta=(BindWidget))
	class UListView* PartyListView;

	UPROPERTY(meta=(BindWidget))
	class UTextBlock* StatusTextBlock;
};
