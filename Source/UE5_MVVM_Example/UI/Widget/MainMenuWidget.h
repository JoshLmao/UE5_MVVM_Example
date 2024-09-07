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
    class UVM_PlayerHealth* TryGetVM();

    void OnFieldChanged(UObject* Object, UE::FieldNotification::FFieldId FieldId);
    
    UPROPERTY(meta=(BindWidget))
    class UProgressBar* HealthProgressBar;
};
