#include "UE5_MVVM_Example/Player/Core/MyPawn.h"

#include "UE5_MVVM_Example/Player/Component/TakeDamageComponent.h"

AMyPawn::AMyPawn()
{
	const auto DamageComponent = CreateDefaultSubobject<UTakeDamageComponent>("TakeDamage");
}
