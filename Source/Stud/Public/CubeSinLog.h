// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "CubeSinLog.generated.h"

UENUM(BlueprintType)
enum class EMovementType :uint8 {
	Sin,
	Static
};

USTRUCT(BlueprintType)
struct FGeometryData {
	GENERATED_USTRUCT_BODY()
	// Movement Trans
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float Frequency = 2.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float Amplitude = 80.0f;

	// Init Enum
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	EMovementType MovementType = EMovementType::Static;

	//---------------------- For Material -------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MaterialCustom")
	FLinearColor Color = FLinearColor::Black;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MaterialCustom")
	float TimerRate = 3.0f;
};


UCLASS()
class STUD_API ACubeSinLog : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACubeSinLog();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* BaseMesh;

	// Для логирования
	int i = 10;
	float f = 10.1f;

	FVector InitionLocation;

	UFUNCTION(BlueprintCallable)
	void SetGeometryData(const FGeometryData& Data) { GeometryData = Data; }
	UFUNCTION(BlueprintCallable)
	FGeometryData GetGeometryData() const { return GeometryData; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "GeometryData")
	FGeometryData GeometryData;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void NewPrint();
	void MovementTrans();
	void SetColor(const FLinearColor);
};
