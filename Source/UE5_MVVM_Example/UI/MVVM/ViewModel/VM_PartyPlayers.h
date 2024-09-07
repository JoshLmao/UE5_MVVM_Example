#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "VM_PartyPlayers.generated.h"

USTRUCT(BlueprintType)
struct FPartyPlayer
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
	const TArray<FPartyPlayer>& GetPlayers() const
	{
		return Players;
	}

	void SetPlayers(const TArray<FPartyPlayer>& InPlayers)
	{
		Players = InPlayers;
	}
	
	void AddPlayer(const FText& Name)
	{
		Players.Add(FPartyPlayer{Name});
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
	TArray<FPartyPlayer> Players;

	UPROPERTY(BlueprintReadOnly, FieldNotify, Getter, Setter, meta=(AllowPrivateAccess))
	EPartyStatus Status;
};
