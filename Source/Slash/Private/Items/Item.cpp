

#include "Items/Item.h"

AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AItem::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("BeginePlay"));
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	for (int32 index = 0; index <= 10; ++index)
	{
		UE_LOG(LogTemp, Warning, TEXT("Tick"));
	} 
}

