// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
// #include "VariablesDebugCommon.h"
#include "ShowDebugWidget.generated.h"

/**
 *
 */
UCLASS(BlueprintType, Blueprintable)
class VARIABLESDEBUG_API UShowDebugWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    //* Function called when variables are updated. Returning list of updated variables */
    UFUNCTION(BlueprintNativeEvent, Category = "Variables")
        void OnVariablesUpdated(const TMap<FName, FString>& VariablesList); //this is actual Event in Blueprint
    
    void OnVariablesUpdated_Implementation(const TMap<FName, FString>& VariablesList);  // this is function that can be used in C++ (not visible in Blueprints)
};
