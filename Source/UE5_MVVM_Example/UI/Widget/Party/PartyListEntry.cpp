// Fill out your copyright notice in the Description page of Project Settings.


#include "PartyListEntry.h"

#include <Components/TextBlock.h>
#include "UE5_MVVM_Example/UI/MVVM/ViewModel/VM_PartyPlayers.h"

void UPartyListEntry::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	if (auto PartyMemberData = Cast<UPartyPlayer>(ListItemObject))
	{
		MemberData = PartyMemberData;
	}

	UpdateVisuals();
}

void UPartyListEntry::UpdateVisuals()
{
	if (!IsValid(MemberData))
	{
		return;
	}
	
	NameTextBlock->SetText(MemberData->Name);
}
