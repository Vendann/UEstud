// Fill out your copyright notice in the Description page of Project Settings.


#include "ArcanoidBall.h"

// Sets default values
AArcanoidBall::AArcanoidBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	SetRootComponent(StaticMesh);
	Direction = FVector(1.f, 0.f, 0.f);
	Speed = 100.f;
}

// Called when the game starts or when spawned
void AArcanoidBall::BeginPlay()
{
	Super::BeginPlay();
	Direction.Normalize();
}

// Called every frame
void AArcanoidBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	StaticMesh->AddWorldOffset(Direction * Speed * DeltaTime, true, &HitResult);

	if (HitResult.bBlockingHit) {
		HandleCollision(HitResult);
		HitResult.Reset();
	}
}

void AArcanoidBall::HandleCollision(const FHitResult& HitResultt)
{
	FVector ReflectionVector = FMath::GetReflectionVector(Direction, HitResultt.Normal);
	Direction = ReflectionVector;
}