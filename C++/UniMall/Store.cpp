#include "Store.h"
#include <vector> 
#include <stdio.h>

Store::Store()
{
	this->storeName = "";
	this->storeItems = vector<Item>();
}

Store::Store(string storeName)
{
	this->storeName = storeName;
	this->storeItems =  vector<Item>();
}
void Store::displayItemList() {

	for (int i =0; i < storeItems.size(); i++) {
		Item currentItem = storeItems.at(i);
		printf("[%d] %s (%d) - Php%g\n", i,currentItem.itemName.c_str(), currentItem.itemCount, currentItem.itemPrice);
	}
	cout << endl;
}
void Store::addItem(Item item)
{
	int existingItemIndex = -1;
	for (int i = 0; i < storeItems.size(); i++)
	{
		Item currentItem = storeItems.at(i);
		if (currentItem.itemName == item.itemName) {
			existingItemIndex = i;
			break;
		}
	}
	if (existingItemIndex != -1)
		storeItems.at(existingItemIndex).itemCount += 1;
	else
		storeItems.push_back(item);
}


Item Store::getItemAtIndex(int itemIndex)
{
	if(itemIndex < storeItems.size())
	return storeItems[itemIndex];
}
