// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
// #include "ShowDebugWidget.h"  //need to include this to be able to declare UShowDebugWidget
// #include "WidgetComponent.h" //this as well to declare UWidgetComponent
// #include "VariablesDebugCommon.h"
#include "ShowDebugComponent.generated.h"


class UWidgetComponent;
class UShowDebugWidget;


/**
* With this component you can add WidgetComponent drawing list of variables. USE THIS ONLY WHEN DEBUGGING as it 2ms per each component!
*/
UCLASS(Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class VARIABLESDEBUG_API UShowDebugComponent : public UActorComponent
{
    GENERATED_BODY()

protected:
    UPROPERTY(BlueprintReadOnly)
        TMap<FName, FString> Variables;

public:
    // Sets default values for this component's properties
    UShowDebugComponent();

    // Called when the game starts
    virtual void BeginPlay() override;

    // Called every frame
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    //* Choose which variables should be show in debug widget */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
        TArray<FName> VariablesNames;

    //** Get variables from VariablesNames and update their values */
    UFUNCTION(BlueprintCallable, Category = "Variables")
        void UpdateVariables();

    UFUNCTION(BlueprintCallable, Category = "Variables")
    const TMap<FName, FString> &GetVariables() const { return Variables; }

    //*Which Widget should be added to WidgetComponent */
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Variables")
        TSubclassOf<class UShowDebugWidget> ShowDebugWidgetClass;

    //*Do we want to use Custom Tick Interval or just Tick? */
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Variables")
        bool isUsingCustomTickInterval;

    //*If using custom tick interval store interval timer */
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Variables")
        float CustomTickInterval;

    //* Storing reference to created WidgetComponent*/
    UPROPERTY()
        UWidgetComponent* WidgetComponentRef;

    //* Storing reference to ShowDebugWidget UMG widget */
    UPROPERTY()
        UShowDebugWidget* ShowDebugWidgetRef;
};
