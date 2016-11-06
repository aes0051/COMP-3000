// Annie Sauer
// ZyBooks Chapter 7 
// Compile: g++ ShoppingCart.cpp ItemtoPurchase.cpp main.cpp -Wall -o a.out
// Run: ./a.out

#include <iostream>
using namespace std;

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

int main() {
ShoppingCart class1; 
string name;
string date;

cout << "Enter Customer's Name: " << endl;
getline (cin, name);
cout << "Enter Today's Date: " << endl;
getline (cin, date);
class1.SetCustomerName(name);
class1.SetCurrentDate(date);
cout << "Customer Name: " << class1.GetCustomerName() << endl;
cout << "Today's Date: " << class1.GetDate() << endl;

class1.PrintMenu();

return 0;
}
