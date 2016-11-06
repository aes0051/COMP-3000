#ifndef STOREITEM_H
#define STOREITEM_H

#include "ItemToPurchase.h"

class ShoppingCart {
	public:
	ShoppingCart();
	ShoppingCart(string name, string date);
	string GetCustomerName();
	string GetDate();
	void AddItem(ItemToPurchase);
	void DeleteItem(string item);
	void ModifyItem(ItemToPurchase);
	int GetNumItemsInCart();
	int GetCostOfCart();
	void PrintTotal();
	void PrintDescriptions();
	private:
	string customerName;
	string currentDate;
};
 #endif
