// UniMall.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector> 
using namespace std;

struct Item {
	string itemName;
	int itemCount;
	float itemPrice;
	Item(string itemName, int itemCount, float itemPrice) {
		this->itemName = itemName;
		this->itemPrice = itemPrice;
		this->itemCount = itemCount;
	}
};

struct Store {
	string storeName;
	vector<Item> storeItems;
	Store() {
		this->storeName = "";
		this->storeItems = vector<Item>();
	}
	Store(string storeName) {
		this->storeName = storeName;
		this->storeItems = vector<Item>();
	}
};
struct MallGuest {

	string guestName;
	float guestCredit;
	vector<Item> boughtItems;
	Store guestCurrentStore;
	MallGuest(string guestName) {
		this->guestName = guestName;
		this->guestCredit = 50000;
		this->boughtItems = vector<Item>();
		this->guestCurrentStore = Store();
	}
};
void addItemToStore(Item itemToAdd, Store& store) {
	int existingItemIndex = -1;
	for (int i = 0; i < store.storeItems.size(); i++)
	{
		Item currentItem = store.storeItems.at(i);
		if (currentItem.itemName == itemToAdd.itemName) {
			existingItemIndex = i;
			break;
		}
	}
	if (existingItemIndex != -1)
		store.storeItems.at(existingItemIndex).itemCount += 1;
	else
		store.storeItems.push_back(itemToAdd);
}
void displayStoreInventory(Store store) {
	for (int i = 0; i < store.storeItems.size(); i++) {
		Item currentItem = store.storeItems.at(i);
		printf("[%d] %s (%d) - Php%g\n", i, currentItem.itemName.c_str(), currentItem.itemCount, currentItem.itemPrice);
	}
	cout << endl;
}
Item getItemAtIndexForStore(int itemIndex, Store store)
{
	if (itemIndex < store.storeItems.size())
		return store.storeItems[itemIndex];
}
void makeGuestEnterStore(MallGuest& guest, Store& store) {
	if (store.storeName != guest.guestCurrentStore.storeName) {
		printf("%s has entered %s", guest.guestName.c_str(), store.storeName.c_str());
		guest.guestCurrentStore = store;
		cout << endl;
	}
}
void addItemToGuestInventory(Item item, MallGuest& guest)
{
	item.itemCount = 1;
	int existingItemIndex = -1;
	for (int i = 0; i < guest.boughtItems.size(); i++)
	{
		Item currentItem = guest.boughtItems.at(i);
		if (currentItem.itemName == item.itemName) {
			existingItemIndex = i;
			break;
		}
	}
	if (existingItemIndex != -1)
		guest.boughtItems.at(existingItemIndex).itemCount += 1;
	else
		guest.boughtItems.push_back(item);
}
void makeGuestPurchaseItemAtIndexOfCurrentStore(MallGuest& guest, int itemIndex) {
	Item itemToPurchase = getItemAtIndexForStore(itemIndex, guest.guestCurrentStore);
	if (itemToPurchase.itemPrice > guest.guestCredit) {
		cout << "Not enough credit to buy " << itemToPurchase.itemName;
	}
	else {
		guest.guestCredit -= itemToPurchase.itemPrice;
		addItemToGuestInventory(itemToPurchase, guest);
		printf("%s has bought %s\n%s's credit is %g\n", guest.guestName.c_str(), itemToPurchase.itemName.c_str(), guest.guestName.c_str(), guest.guestCredit);
	}
}
void displayGuestInventory(MallGuest guest) {

	printf("%s's Inventory:\n", guest.guestName.c_str());
	for (int i = 0; i < guest.boughtItems.size(); i++) {
		Item currentItem = guest.boughtItems.at(i);
		printf(">%s (%d)", currentItem.itemName.c_str(), currentItem.itemCount);
	}
	cout << endl << endl;
}


int main()
{
	Store adidasStore = Store("Nike");
	addItemToStore(Item("Sneakers", 10, 1200.75), adidasStore);
	addItemToStore(Item("Shirt", 5, 800.99), adidasStore);
	addItemToStore(Item("Cap", 7, 500), adidasStore);
	displayStoreInventory(adidasStore);


	MallGuest guest1 = MallGuest("QWERTY");

	makeGuestEnterStore(guest1, adidasStore);
	makeGuestPurchaseItemAtIndexOfCurrentStore(guest1, 0);
	displayGuestInventory(guest1);

	MallGuest guest2 = MallGuest("ASDF");

	makeGuestEnterStore(guest2, adidasStore);
	makeGuestPurchaseItemAtIndexOfCurrentStore(guest2, 2);
	displayGuestInventory(guest2);

}

