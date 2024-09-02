#include <CoreMinimal.h>
#include <GameFramework/HUD.h>
#include "MyHUD.generated.h"

UCLASS()
class AMyHUD : public AHUD
{
	GENERATED_BODY()

protected:
	void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> MainMenuWidgetClass;

	UPROPERTY()
	class UUserWidget* MainMenuWidget;
};
