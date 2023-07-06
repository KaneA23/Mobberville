#pragma once

#include "CoreMinimal.h"

#include "InventoryStack.h"

#include "Inventory.generated.h"

UCLASS()
class MOBBERVILLE_API UInventory : public UObject
{
	GENERATED_BODY()
public:
	UInventory();

	UFUNCTION(BlueprintCallable, Category="SubInventory")
	int32 MaxSize();

	UFUNCTION(BlueprintCallable, Category="SubInventory")
	void SetMaxSize(int32 newSize);

	UFUNCTION(BlueprintCallable, Category="SubInventory")
	const TArray<FInventoryStack>& GetItems();

	UFUNCTION(BlueprintCallable, Category = "SubInventory")
		int64 AddItem(AItem* item, int64 count = 1);
protected:
	UPROPERTY(EditAnywhere)
	int32 size = 10;

	UPROPERTY(EditAnywhere)
	TArray<FInventoryStack> items;
};
