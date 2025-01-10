// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

class UStaticMeshComponent;

UCLASS()
class ACTIONROGUE_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ABC")
	float whenIDissapear = 3.f;

	UPROPERTY()
	FTimerHandle isHandle;

	UFUNCTION()
	void DestroyActor();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
