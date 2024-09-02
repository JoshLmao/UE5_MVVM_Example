#include "UE5_MVVM_Example/Player/Component/TakeDamageComponent.h"

#include "UE5_MVVM_Example/Core/MyPlayerState.h"

void UTakeDamageComponent::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(TakeDamageHandle,this, &ThisClass::OnTakeDamageTick, 2.0f, true);
}

void UTakeDamageComponent::OnTakeDamageTick()
{
	const auto Pawn = Cast<APawn>(GetOwner());
	auto PlayerState = Pawn->GetController()->GetPlayerState<AMyPlayerState>();
	PlayerState->SetCurrentHealth(PlayerState->GetCurrentHealth() - 1.0f);
}
