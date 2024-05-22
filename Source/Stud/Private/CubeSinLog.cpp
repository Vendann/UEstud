// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeSinLog.h"
#include "Materials/MaterialInstanceDynamic.h"


DEFINE_LOG_CATEGORY_STATIC(AMyLogGeometryBase, All, All);

// Sets default values
ACubeSinLog::ACubeSinLog()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	SetRootComponent(BaseMesh);
}

// Called when the game starts or when spawned
void ACubeSinLog::BeginPlay()
{
	Super::BeginPlay();
	NewPrint();
	SetColor(GeometryData.Color);
}

// Called every frame
void ACubeSinLog::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	switch (GeometryData.MovementType)
	{
	case EMovementType::Sin:
	{
		MovementTrans();
	}
	break;
	case EMovementType::Static:
		break;
	default:
		break;
	}
}

void ACubeSinLog::NewPrint()
{
	bool b = true;
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Black, TEXT("bibki"), true, { 2, 2 });
	UE_LOG(AMyLogGeometryBase, Display, TEXT("int: %d"), i);
	UE_LOG(AMyLogGeometryBase, Warning, TEXT("float: %f"), f);
	UE_LOG(AMyLogGeometryBase, Error, TEXT("string: %s"), *GetName());
	UE_LOG(AMyLogGeometryBase, Error, TEXT("string: %s"));
}

void ACubeSinLog::MovementTrans()
{
	FVector CurrentLocation = GetActorLocation();
	float Time = GetWorld()->GetTimeSeconds();
	CurrentLocation.Z = InitionLocation.Z + GeometryData.Amplitude *
		FMath::Sin(Time * GeometryData.Frequency);
	SetActorLocation(CurrentLocation);
}

void ACubeSinLog::SetColor(const FLinearColor Color)
{
	UMaterialInstanceDynamic* DynMat = BaseMesh->CreateAndSetMaterialInstanceDynamic(0);
	if (DynMat) {
		DynMat->SetVectorParameterValue("Color", Color);
	}
}

