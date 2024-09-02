#include "UE5_MVVM_Example/Core/MyGameModeBase.h"

#include "UE5_MVVM_Example/Core/MyPlayerController.h"
#include "UE5_MVVM_Example/Core/MyPlayerState.h"
#include "UE5_MVVM_Example/UI/Core/MyHUD.h"

AMyGameModeBase::AMyGameModeBase()
{
	HUDClass = AMyHUD::StaticClass();
	PlayerStateClass = AMyPlayerState::StaticClass();
	PlayerControllerClass = AMyPlayerController::StaticClass();
}
