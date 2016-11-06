#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

void ItemToPurchase::SetName(string name) {
	itemName = name;
	return;
}

string ItemToPurchase::GetName() {
	return itemName;
}

void ItemToPurchase::SetPrice(int price) {
	itemPrice = price;
	return;
}

int ItemToPurchase::GetPrice() {
	return itemPrice;
}

void ItemToPurchase::SetQuantity(int quantity) {
	itemQuantity = quantity;
	return;
}

int ItemToPurchase::GetQuantity() {
	return itemQuantity;
}
