#include "UE5_MVVM_Example/UI/Core/MyHUD.h"

#include "Blueprint/UserWidget.h"

void AMyHUD::BeginPlay()
{
	Super::BeginPlay();

	MainMenuWidget = CreateWidget<UUserWidget>(GetOwningPlayerController(), MainMenuWidgetClass);
	MainMenuWidget->AddToViewport();

	auto InputMode = FInputModeUIOnly();
	InputMode.SetWidgetToFocus(MainMenuWidget->TakeWidget());
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	GetOwningPlayerController()->SetInputMode(InputMode);
	
	GetOwningPlayerController()->bShowMouseCursor = true;
}
