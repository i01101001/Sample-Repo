// UniMall.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Store.h"
#include "MallGuest.h"
using namespace std;
int main()
{
	Store adidasStore = Store("Adidas");
	adidasStore.addItem(Item("Sneakers", 10, 1200.75));
	adidasStore.addItem(Item("Shirt", 6, 120.75));
	adidasStore.addItem(Item("Cap", 7, 987));
	adidasStore.addItem(Item("Sneakers", 10, 999975));
	adidasStore.displayItemList();


	MallGuest guest1 = MallGuest("QWERTY");

	guest1.entetStore(adidasStore);
	guest1.purchaseItem(adidasStore.getItemAtIndex(0));

	MallGuest guest2 = MallGuest("QWERTY");

	guest2.entetStore(adidasStore);
	guest2.purchaseItem(adidasStore.getItemAtIndex(0));

}

