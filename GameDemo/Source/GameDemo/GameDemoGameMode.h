// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UI/MainUI.h"
#include "GameDemoGameMode.generated.h"

UCLASS(minimalapi)
class AGameDemoGameMode : public AGameModeBase
{
	GENERATED_BODY()
    
    UFUNCTION(BlueprintCallable, Category = "MainUI")
    void ChangeMainUI(TSubclassOf<UUserWidget> NewWidgetClass);

public:
	AGameDemoGameMode();
    
    virtual void BeginPlay() override;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MainUI")
    int TargetNum;
    
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MainUI")
    int CurrentNum;
    
    UFUNCTION()
    bool AddHitAndUpdateMainUI();
    
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MainUI")
    TSubclassOf<UUserWidget> CurrentWidgetClass;
    
    UPROPERTY()
    class UMainUI* CurrentWidget;
    
protected:
    bool isGameEnd;
};



