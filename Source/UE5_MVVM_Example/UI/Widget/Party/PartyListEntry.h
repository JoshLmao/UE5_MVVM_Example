#pragma once

#include "CoreMinimal.h"
#include <Blueprint/IUserObjectListEntry.h>
#include <Blueprint/UserWidget.h>
#include "PartyListEntry.generated.h"

UCLASS()
class UPartyMemberData : public UObject
{
	GENERATED_BODY()

public:
	FText Name;
	FGuid ID;
};

UCLASS(Abstract)
class UE5_MVVM_EXAMPLE_API UPartyListEntry : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:
	void NativeOnListItemObjectSet(UObject* ListItemObject) override;
	
private:
	void UpdateVisuals();
	
	UPROPERTY(meta=(BindWidget))
	class UTextBlock* NameTextBlock;

	UPROPERTY()
	UPartyMemberData* MemberData;
};
