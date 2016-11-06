#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

int main() {

ItemToPurchase item1;
ItemToPurchase item2;

string name1;
string name2;
int price1;
int price2;
int quantity1;
int quantity2;

cout << "Item 1" << endl;
cout << "Enter the item name: " << endl;
cin >> name1;
item1.SetName(name1);
cout << "Enter the item price: " << endl;
cin >> price1;
item1.SetPrice(price1);
cout << "Enter the item quantity: " << endl;
cin>> quantity1;
item1.SetQuantity(quantity1);

cin.ignore();

cout << "Item 2" << endl;
cout << "Enter the item name: " << endl;
cin >> name2;
item2.SetName(name2);
cout << "Enter the item price: " << endl;
cin >> price2;
item2.SetPrice(price2);
cout << "Enter the item quantity: " << endl;
cin >> quantity2;
item2.SetQuantity(quantity2);
cout << "Enter the item name: " << endl;

int cost1;
int cost2;
int totalcost;

cost1 = item1.GetPrice() * item1.GetQuantity();
cost2 = item2.GetPrice() * item2.GetQuantity();

totalcost = cost1 + cost2;

cout << "TOTAL COST" << endl;
cout << item1.GetName() << " " << item1.GetQuantity() << " @ $" << item1.GetPrice() << " = $" << cost1 << endl;
cout << item2.GetName() << " " << item2.GetQuantity() << " @ $" << item2.GetPrice() << " = $" << cost2 << endl;
cout << endl << "Total: $" << totalcost;


return 0;
}

