// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemBase.generated.h"

UCLASS()
class GAMEDEMO_API AItemBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemBase();
    
    //class UBoxComponent* collisionBox;
    
    UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "StaticMeshComp")
    class UStaticMeshComponent* itemMesh;
    
    UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "ItemName")
    FString itemName;
    
    
    virtual void NotifyHit(class UPrimitiveComponent* MyComp, class AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
