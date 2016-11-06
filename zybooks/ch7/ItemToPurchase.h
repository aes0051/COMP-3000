#ifndef STOREITEM_H
#define STOREITEM_H

class ItemToPurchase {
	public:
	void SetName(string name);
	string GetName();
	void SetPrice(int price);
	int GetPrice();
	void SetQuantity(int quantity);
	int GetQuantity();
	private:
	string itemName;
	int itemPrice;
	int itemQuantity;
};

#endif

