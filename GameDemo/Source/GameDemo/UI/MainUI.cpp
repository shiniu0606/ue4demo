// Fill out your copyright notice in the Description page of Project Settings.


#include "MainUI.h"
#include "Widgets/SWidget.h"
#include "Components/ContentWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Internationalization/Text.h"
#include "Kismet/KismetStringLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

bool UMainUI::Initialize()
{
    Super::Initialize();
 
    btn_stop = Cast<UButton>(GetWidgetFromName("btn_stop"));
    if (btn_stop != nullptr)
    {
        FScriptDelegate Del;
        Del.BindUFunction(this, "QuitGame");
        //QuitGameBtn->OnClicked.AddDynamic(this, &UMainUI::QuitGame);
        btn_stop->OnClicked.Add(Del);
    }
    
    txt_hit_num = Cast<UTextBlock>(GetWidgetFromName("txt_hit_num"));
    if(txt_hit_num != nullptr)
    txt_hit_num->SetText(FText::FromString(TEXT("test")));
    
    txt_desc = Cast<UTextBlock>(GetWidgetFromName("txt_desc"));
    if(txt_desc != nullptr)
    txt_desc->SetText(FText::FromString(TEXT("")));
    //UE_LOG(LogTemp, Warning, TEXT("Initialize"));
    return true;
}

void UMainUI::QuitGame()
{
    UE_LOG(LogTemp, Warning, TEXT("btn clicked"));
    
    UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit,true);
}

void UMainUI::UpdateHitNum(int curNum,int targetNum)
{
    FString str = FString::Printf(TEXT(" %d / %d"),curNum,targetNum);
    txt_hit_num->SetText(FText::FromString(str));
}

void UMainUI::UpdateGameDesc(bool succeed)
{
    if(succeed)
    {
        txt_desc->SetText(FText::FromString(TEXT("game successful！")));
    }
    else
    {
        txt_desc->SetText(FText::FromString(TEXT("game over！")));
    }
}

