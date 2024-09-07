#include <CoreMinimal.h>
#include <Blueprint/UserWidget.h>
#include "MainMenuWidget.generated.h"

UCLASS(Abstract)
class UMainMenuWidget : public UUserWidget
{
    GENERATED_BODY()

protected:
    void NativeOnInitialized() override;
    void NativePreConstruct() override;
    void NativeConstruct() override;

private:
    class UObject* TryGetVM();
};
