#include "MyBaseUserWidget.h"

#include <MVVMGameSubsystem.h>
#include <MVVMViewModelBase.h>
//
// template <typename VMClass>
// VMClass* UMyBaseUserWidget::TryGetViewModel() const
// {
// 	const auto Collection = GetGameInstance()->GetSubsystem<UMVVMGameSubsystem>()->GetViewModelCollection();
// 	
// 	FMVVMViewModelContext Context;
// 	Context.ContextClass = ViewModelClass->StaticClass();
// 	Context.ContextName = ViewModelName;
// 	const auto VMInstance = Collection->FindViewModelInstance(Context);
// 	if (IsValid(VMInstance))
// 	{
// 		return Cast<VMClass>(VMInstance);
// 	}
// 	checkf(false, TEXT("Unable to find a ViewModel that matches the given ViewModelName and ViewModelClass!"));
// 	return nullptr;
// }
