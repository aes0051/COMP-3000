#ifndef STOREITEM_H
#define STOREITEM_H

class ItemToPurchase {
	public:
	ItemToPurchase();
	void SetName(string name);
	string GetName();
	void SetDescription(string description);
	string GetDescription();	
	void SetPrice(int price);
	int GetPrice();
	void SetQuantity(int quantity);
	int GetQuantity();
	void PrintItemCost();
	void PrintItemDescription();
	private:
	string itemName;
	string itemDescription;
	int itemPrice;
	int itemQuantity;
};

#endif

