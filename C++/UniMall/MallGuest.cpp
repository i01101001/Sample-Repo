#include "MallGuest.h"

MallGuest::MallGuest(string guestName)
{
	this->guestName = guestName;
	this->guestCredit = 50000;
	this->boughtItems = vector<Item>();
}

void MallGuest::purchaseItem(Item itemToPurchase)
{
	if (itemToPurchase.itemPrice > guestCredit) {
		cout << "Not enough credit to buy " << itemToPurchase.itemName;
	}
	else {
		guestCredit -= itemToPurchase.itemPrice;
		addItem(itemToPurchase);
		printf("%s has bought %s\nYour guest credit is %g\n", guestName.c_str(), itemToPurchase.itemName.c_str(), guestCredit);
	}
}
void MallGuest::addItem(Item item)
{
	item.itemCount = 1;
	int existingItemIndex = -1;
	for (int i = 0; i < boughtItems.size(); i++)
	{
		Item currentItem = boughtItems.at(i);
		if (currentItem.itemName == item.itemName) {
			existingItemIndex = i;
			break;
		}
	}
	if (existingItemIndex != -1)
		boughtItems.at(existingItemIndex).itemCount += 1;
	else
		boughtItems.push_back(item);
}
void MallGuest::entetStore(Store storeToEnter)
{
	if (storeToEnter.storeName != guestCurrentStore.storeName) {
		printf("%s has entered %s", guestName.c_str(), storeToEnter.storeName.c_str());
		guestCurrentStore = storeToEnter;
		cout << endl;
	}
}
