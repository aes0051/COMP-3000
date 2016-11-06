#include <iostream>
using namespace std;

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

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
        private:
        string customerName;
        string currentDate;
};

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













return 0;
}
