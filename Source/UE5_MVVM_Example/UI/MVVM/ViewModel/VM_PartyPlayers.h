#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "VM_PartyPlayers.generated.h"

UCLASS(BlueprintType)
class UPartyPlayer : public UObject
{
	GENERATED_BODY()

public:
	// Display name
	UPROPERTY(BlueprintReadOnly)
	FText Name;

	// Random generated ID
	UPROPERTY(BlueprintReadOnly)
	FGuid ID = FGuid();
};

UENUM()
enum class EPartyStatus : uint8
{
	Ready,
	NotReady,
};

UCLASS()
class UE5_MVVM_EXAMPLE_API UVM_PartyPlayers : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	const TArray<UPartyPlayer*>& GetPlayers() const
	{
		return Players;
	}

	void SetPlayers(const TArray<UPartyPlayer*>& InPlayers)
	{
		Players = InPlayers;
	}
	
	void AddPlayer(const FText& Name)
	{
		auto Player = NewObject<UPartyPlayer>(this);
		Player->Name = Name;
		Players.Add(Player);
		UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(Players);
	}

	void RemovePlayer(int Index)
	{
		Players.RemoveAt(Index);
		UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(Players);
	}

	EPartyStatus GetStatus() const
	{
		return Status;
	}
	
	void SetStatus(EPartyStatus InStatus)
	{
		UE_MVVM_SET_PROPERTY_VALUE(Status, InStatus);
	}

private:
	// Array of members of the party
	UPROPERTY(BlueprintReadOnly, FieldNotify, Getter, Setter, meta=(AllowPrivateAccess))
	TArray<UPartyPlayer*> Players;

	UPROPERTY(BlueprintReadOnly, FieldNotify, Getter, Setter, meta=(AllowPrivateAccess))
	EPartyStatus Status;
};
