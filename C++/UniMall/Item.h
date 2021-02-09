#pragma once
#include <iostream>
using namespace std;
class Item
{
public:
	Item(string itemName, int itemCount, float itemPrice);
	string itemName;
	int itemCount;
	float itemPrice;
};

