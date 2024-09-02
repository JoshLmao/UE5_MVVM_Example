#include "UE5_MVVM_Example/Player/Component/TakeDamageComponent.h"

#include <TimerManager.h>
#include <GameFramework/Actor.h>
#include <GameFramework/Pawn.h>
#include <GameFramework/PlayerController.h>
#include <GameFramework/Controller.h>
#include <Engine/World.h>

#include "UE5_MVVM_Example/Core/MyPlayerState.h"

void UTakeDamageComponent::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(TakeDamageHandle,this, &UTakeDamageComponent::OnTakeDamageTick, 2.0f, true);
}

void UTakeDamageComponent::OnTakeDamageTick() const
{
	const auto Pawn = Cast<APawn>(GetOwner());

	auto PlayerState = Pawn->GetController()->GetPlayerState<AMyPlayerState>();
	PlayerState->SetCurrentHealth(PlayerState->GetCurrentHealth() - 1.0f);
}
