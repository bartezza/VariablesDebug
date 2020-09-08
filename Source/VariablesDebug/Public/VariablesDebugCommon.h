#pragma once

#include "CoreMinimal.h"
#include "VariablesDebugCommon.generated.h"


USTRUCT(BlueprintType)
struct FDebugVariable
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug Variable")
        FName Name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug Variable")
        FString Value;

    void SetName(const FName NewValue)
    {
        Name = NewValue;
    }

    void SetValue(const FString NewValue)
    {
        Value = NewValue;
    }

    FDebugVariable()
    {
        Name = "None";
        Value = "None";
    }

};
