#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase() : itemName("1"), itemDescription("none"), itemPrice(1), itemQuantity(1) {
	return;
}

void ItemToPurchase::SetName(string name) {
	itemName = name;
	return;
}

string ItemToPurchase::GetName() {
	return itemName;
}

void ItemToPurchase::SetDescription(string description) {
	itemDescription = description;
	return;
}

string ItemToPurchase::GetDescription() {
	return itemDescription;
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

void ItemToPurchase::PrintItemCost() {
	cout << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $"<< (itemPrice*itemQuantity) << endl;
	return;
}

void ItemToPurchase::PrintItemDescription() {
	cout << itemName << ": " << itemDescription << endl;
	return;
}



