#include <CoreMinimal.h>
#include "Core/MyBaseUserWidget.h"
#include "MainMenuWidget.generated.h"

UCLASS(Abstract)
class UMainMenuWidget : public UMyBaseUserWidget
{
    GENERATED_BODY()

public:
    UMainMenuWidget();
    
protected:
    void NativeConstruct() override;

private:
    void OnFieldChanged(UObject* Object, UE::FieldNotification::FFieldId FieldId);
    
    UPROPERTY(meta=(BindWidget))
    class UProgressBar* HealthProgressBar;
};
