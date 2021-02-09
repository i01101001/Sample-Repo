#pragma once
#include "Item.h"
#include <vector> 
class Store
{
public:
	Store();
	Store(string storeName);
	void addItem(Item item);
	void setItems(Item items);
	void displayItemList();
	float returnItemPriceAtIndex(int itemIndex);
	Item getItemAtIndex(int itemIndex);
	string storeName;
private:
	vector<Item> storeItems;
};

