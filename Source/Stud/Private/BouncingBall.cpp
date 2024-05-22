// Fill out your copyright notice in the Description page of Project Settings.


#include "BouncingBall.h"

// Sets default values
ABouncingBall::ABouncingBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	BaseMesh->SetSimulatePhysics(true);
	
	SetRootComponent(BaseMesh);
}

// Called when the game starts or when spawned
void ABouncingBall::BeginPlay()
{
	Super::BeginPlay();
	BaseMesh->OnComponentHit.AddDynamic(this, &ABouncingBall::OnHit);
}

// Called every frame
void ABouncingBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABouncingBall::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Black, TEXT("bibki"), true, { 2, 2 });
	BaseMesh->AddImpulse({ 0, 0, force });
}