#include "ShoppingCart.h"

ShoppingCart::ShoppingCart()
{
	this->payMethod = "-";
}

ShoppingCart::ShoppingCart(const string &payMethod)
{
	this->payMethod=payMethod;
	//throw("undefined");
}

string &ShoppingCart::getPayMethod()
{
	return payMethod;
	//throw("undefined");
}

void ShoppingCart::setPayMethod(const string &payMethod)
{
	this->payMethod=payMethod;
	//throw("undefined");
}

void ShoppingCart::addProduct(int id, int quantity)
{
	shoppingCart.insert(pair<int,int>(id,quantity));
	//throw("undefined");
}

void ShoppingCart::raiseQuantity(int id, int quantity)
{
	shoppingCart[id]=shoppingCart[id]+quantity;
	//throw("undefined");
}

void ShoppingCart::lowerQuantity(int id, int quantity)
{
	shoppingCart[id]=shoppingCart[id]-quantity;
	//throw("undefined");
}

int ShoppingCart::getQuantity(int productID)
{
	if(shoppingCart.count(productID))
		return shoppingCart[productID];
	else return -1;
	//throw("undefined");
}

void ShoppingCart::deleteProduct(int productID)
{
	shoppingCart.erase(productID);
	//throw("undefined");
}

map<int, int> &ShoppingCart::getShoppingCart()
{
	return shoppingCart;
	//throw("undefined");
}

void ShoppingCart::displayShoppingCart()
{
	throw("undefined");
}

json ShoppingCart::toJSON()
{
  return json(*this);
}