// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemBase.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Engine/CollisionProfile.h"
#include "Engine/StaticMesh.h"
#include "../GameDemoBall.h"

// Sets default values
AItemBase::AItemBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
    static ConstructorHelpers::FObjectFinder<UStaticMesh> BallMesh(TEXT("/Game/Rolling/Meshes/ItemMesh.ItemMesh"));
    
    itemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball0"));
    itemMesh->SetStaticMesh(BallMesh.Object);
    itemMesh->BodyInstance.SetCollisionProfileName(UCollisionProfile::PhysicsActor_ProfileName);
    itemMesh->SetSimulatePhysics(true);
    itemMesh->SetAngularDamping(0.1f);
    itemMesh->SetLinearDamping(0.1f);
    itemMesh->BodyInstance.MassScale = 3.5f;
    itemMesh->BodyInstance.MaxAngularVelocity = 800.0f;
    itemMesh->SetNotifyRigidBodyCollision(true);
    
    //collisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
    RootComponent = itemMesh;
    
    //itemMesh->SetupAttachment(collisionBox);

}

// Called when the game starts or when spawned
void AItemBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItemBase::NotifyHit(class UPrimitiveComponent* MyComp, class AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
    Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

     //UE_LOG(LogTemp, Warning, TEXT("AItemBase NotifyHit"));
    
    AGameDemoBall * ptr = Cast<AGameDemoBall>(Other);
    if(ptr)
    {
        UE_LOG(LogTemp, Warning, TEXT("AItemBase AGameDemoBall NotifyHit"));
        Destroy();
    }
}

