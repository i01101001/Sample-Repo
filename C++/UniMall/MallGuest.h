#pragma once
#include "Item.h"
#include "Store.h"
#include<vector>
class MallGuest
{
public:
	MallGuest(string guestName);
	void purchaseItem(Item itemToPurchase);
	void addItem(Item item);
	void entetStore(Store storeToEnter);
private:
	string guestName;
	float guestCredit;
	vector<Item> boughtItems;
	Store guestCurrentStore;
	string guestID;
	string guestPass;
};

