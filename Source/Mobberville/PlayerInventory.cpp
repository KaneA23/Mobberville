#include "PlayerInventory.h"

UPlayerInventory::UPlayerInventory()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UPlayerInventory::BeginPlay()
{
	hotbar = NewObject<UInventory>();
	hotbar->SetMaxSize(hotbarSize);
	inventoryUpdateEvent->RegisterInventory(hotbar);

	inventory = NewObject<UInventory>();
	inventory->SetMaxSize(inventorySize);
	inventoryUpdateEvent->RegisterInventory(inventory);
}

int64 UPlayerInventory::AddItem(TSubclassOf<AItemInstance> item, int64 count)
{
	if (count > 0) count = hotbar->AddItem(item, count);
	if (count > 0) count = inventory->AddItem(item, count);

	return count;
}

int64 UPlayerInventory::HasItem(TSubclassOf<AItemInstance> item)
{
	int64 count = 0;
	count += hotbar->HasItem(item);
	count += inventory->HasItem(item);

	return count;
}

int64 UPlayerInventory::RemoveItem(TSubclassOf<AItemInstance> item, int64 count)
{
	if (count > 0) count = hotbar->RemoveItem(item, count);
	if (count > 0) count = hotbar->RemoveItem(item, count);

	return count;
}

FInventoryStack& UPlayerInventory::GetEquippedItemStack()
{
	return hotbar->items[equippedIndex];
}
