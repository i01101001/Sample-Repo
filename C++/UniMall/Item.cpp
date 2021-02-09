#include "Item.h"

Item::Item(string itemName, int itemCount, float itemPrice)
{
	this->itemName = itemName;
	this->itemPrice = itemPrice;
	this->itemCount = itemCount;
}
