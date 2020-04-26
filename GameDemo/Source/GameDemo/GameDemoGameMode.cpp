// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "GameDemoGameMode.h"
#include "GameDemoBall.h"

AGameDemoGameMode::AGameDemoGameMode()
:TargetNum(0),
CurrentNum(0),
CurrentWidgetClass(nullptr),
CurrentWidget(nullptr),
isGameEnd(false)

{
	// set default pawn class to our ball
	DefaultPawnClass = AGameDemoBall::StaticClass();
}

void AGameDemoGameMode::BeginPlay()
{
    Super::BeginPlay();
    
    ChangeMainUI(CurrentWidgetClass);
    
    if (CurrentWidget != nullptr)
    {
         CurrentWidget->UpdateHitNum(CurrentNum,TargetNum);
    }
}

void AGameDemoGameMode::ChangeMainUI(TSubclassOf<UUserWidget> NewWidgetClass)
{
    //UE_LOG(LogTemp, Log,TEXT("ChangeMainUI 1"));
    if (CurrentWidget != nullptr)
    {
        CurrentWidget->RemoveFromViewport();
        CurrentWidget = nullptr;
    }
    if (NewWidgetClass != nullptr)
    {
        //UE_LOG(LogTemp, Log,TEXT("ChangeMainUI 2"));
        CurrentWidget = CreateWidget<UMainUI>(GetWorld(), NewWidgetClass);
        if (CurrentWidget != nullptr)
        {
            CurrentWidget->AddToViewport();
        }
    }
}

bool AGameDemoGameMode::AddHitAndUpdateMainUI()
{
    CurrentNum++;
    //update ui data
    if (CurrentWidget != nullptr)
    {
        //UE_LOG(LogTemp, Log, TEXT("UpdateMainUI cur:%d  target:%d"),CurrentNum,TargetNum);
        CurrentWidget->UpdateHitNum(CurrentNum,TargetNum);
    }
    
    if(CurrentNum>=TargetNum)
    {
        isGameEnd = true;
        CurrentWidget->UpdateGameDesc(true);
    }
    
    return isGameEnd;
}
