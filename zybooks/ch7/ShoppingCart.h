#ifndef STOREITEM_H
#define STOREITEM_H

#include "ItemToPurchase.h"

class ShoppingCart {
	public:
	ShoppingCart();
	ShoppingCart(string name, string date);
	void SetCustomerName(string name);
	void SetCurrentDate(string date);
	string GetCustomerName();
	string GetDate();
	void AddItem(ItemToPurchase);
	void DeleteItem(string item);
	void ModifyItem(ItemToPurchase);
	int GetNumItemsInCart();
	int GetCostOfCart();
	void PrintTotal();
	void PrintDescriptions();
	void PrintMenu();
	private:
	string customerName;
	string currentDate;
};
 #endif
