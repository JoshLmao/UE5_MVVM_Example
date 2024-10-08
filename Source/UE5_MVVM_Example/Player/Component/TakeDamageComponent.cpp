#include "UE5_MVVM_Example/Player/Component/TakeDamageComponent.h"

#include <TimerManager.h>
#include <GameFramework/Actor.h>
#include <GameFramework/Pawn.h>
#include <GameFramework/PlayerController.h>
#include <GameFramework/Controller.h>
#include <Engine/World.h>
#include <MVVMGameSubsystem.h>
#include <MVVMSubsystem.h>

#include "UE5_MVVM_Example/Core/MyPlayerState.h"
#include "UE5_MVVM_Example/UI/MVVM/ViewModel/VM_PlayerHealth.h"

void UTakeDamageComponent::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(TakeDamageHandle,this, &UTakeDamageComponent::OnTakeDamageTick, 2.0f, true);

	// Init with default values
	auto PlayerState = GetPlayerState();
	auto VM = GetVMPlayerHealth();
	
	const int NewMaxHealth = 100;
	PlayerState->SetMaxHealth(NewMaxHealth);
	VM->SetMaxHealth(NewMaxHealth);

	const int NewCurrentHealth = 100;
	PlayerState->SetCurrentHealth(NewCurrentHealth);
	VM->SetCurrentHealth(NewCurrentHealth);
}

void UTakeDamageComponent::OnTakeDamageTick()
{
	auto PlayerState =GetPlayerState();
	PlayerState->SetCurrentHealth(PlayerState->GetCurrentHealth() - 1.0f);

	UpdateCurrentHealth(PlayerState->GetCurrentHealth());
}

void UTakeDamageComponent::UpdateMaxHealth(int32 NewMaxHealth)
{
	const auto VMPlayerHealth = GetVMPlayerHealth();
	if (IsValid(VMPlayerHealth))
	{
		VMPlayerHealth->SetMaxHealth(NewMaxHealth);
	}
}

void UTakeDamageComponent::UpdateCurrentHealth(int32 NewCurrentHealth)
{
	const auto VMPlayerHealth = GetVMPlayerHealth();
	if (IsValid(VMPlayerHealth))
	{
		VMPlayerHealth->SetCurrentHealth(NewCurrentHealth);
	}
}

UVM_PlayerHealth* UTakeDamageComponent::GetVMPlayerHealth()
{
	const auto VMCollection = GetWorld()->GetGameInstance()->GetSubsystem<UMVVMGameSubsystem>()->GetViewModelCollection();
	
	FMVVMViewModelContext Context;
	Context.ContextName = TEXT("VM_PlayerHealth");
	Context.ContextClass = UVM_PlayerHealth::StaticClass();

	const auto Found = VMCollection->FindViewModelInstance(Context);
	return Cast<UVM_PlayerHealth>(Found);
}

AMyPlayerState* UTakeDamageComponent::GetPlayerState()
{
	const auto Pawn = Cast<APawn>(GetOwner());
	auto PlayerState = Pawn->GetController()->GetPlayerState<AMyPlayerState>();
	return PlayerState;
}
