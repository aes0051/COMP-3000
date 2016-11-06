#include <iostream>
using namespace std;

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

ShoppingCart::ShoppingCart() : customerName("none"),currentDate("January 1, 2016") {
return;
}

ShoppingCart::ShoppingCart(string name, string date) {
	customerName = name;
	currentDate = date;
}

void ShoppingCart::SetCustomerName(string name) {
	customerName = name;
return;
}
void ShoppingCart::SetCurrentDate (string date) {
	currentDate = date;
return;
}

string ShoppingCart::GetCustomerName() {
	return customerName;
}

string ShoppingCart::GetDate() {
	return currentDate;
}

void ShoppingCart::PrintMenu() {
	cout << endl << "MENU" << endl;
	cout << "a - Add item to cart" << endl;
	cout << "d - Delete item from cart" << endl;
	cout << "c - Change item quantity" << endl;
	cout << "i - Output items' descriptions" << endl;
	cout << "o - Output shopping cart" << endl;
	cout << "q - Quit" << endl << endl;
	cout << "Choose an option: " << endl;
return;
}

