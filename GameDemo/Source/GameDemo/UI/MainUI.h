// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainUI.generated.h"


/**
 * 
 */
UCLASS()
class GAMEDEMO_API UMainUI : public UUserWidget
{
	GENERATED_BODY()
public:
    virtual bool Initialize() override;
	
    UPROPERTY(Meta = (BindWidget))
    class UTextBlock* txt_hit_num;
    
    UPROPERTY(Meta = (BindWidget))
    class UTextBlock* txt_desc;
    
    UPROPERTY(Meta = (BindWidget))
    class UButton* btn_stop;
    
    UFUNCTION()
    void UpdateHitNum(int curNum,int targetNum);
    
    UFUNCTION()
    void UpdateGameDesc(bool succeed);
    
    UFUNCTION()
    void QuitGame();
};
