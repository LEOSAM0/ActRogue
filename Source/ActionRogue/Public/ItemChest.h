// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ARGameplayInterface.h"
#include "ItemChest.generated.h"

class UStaticMeshComponent;

UCLASS()
class ACTIONROGUE_API AItemChest : public AActor, public IARGameplayInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TargetPitch = 110.f;
	
	void Interact_Implementation(APawn* InstigatorPawn) override;
	
public:	
	// Sets default values for this actor's properties
	AItemChest();

protected:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* LidMesh;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void LidOpen();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
