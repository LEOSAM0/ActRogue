// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemChest.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AItemChest::AItemChest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	RootComponent = BaseMesh;

	LidMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LidMesh"));
	LidMesh->SetupAttachment(BaseMesh);

	TargetPitch = 110.f;
}

// Called when the game starts or when spawned
void AItemChest::BeginPlay()
{
	Super::BeginPlay();
	
}

void AItemChest::LidOpen()
{
	LidMesh->SetRelativeRotation(FRotator(TargetPitch, 0, 0));
}

// Called every frame
void AItemChest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItemChest::Interact_Implementation(APawn* InstigatorPawn)
{
	FTimerHandle OutHandle;
	float handle = 3.f;
	GetWorldTimerManager().SetTimer(OutHandle, this, &AItemChest::LidOpen, handle, false);
	UE_LOG(LogTemp, Warning, TEXT("%f"), handle);
}

