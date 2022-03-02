#include "Server.h"

using namespace std;

/* NU MODIFICATI */
Server::Server() {}

/* NU MODIFICATI */
Server *Server::GetInstance()
{
	if (!instance)
	{
		instance = new Server;
	}
	return instance;
}

/* NU MODIFICATI */
Server::~Server()
{
	if (instance != NULL)
		instance = NULL;

	if (!__UserID__ProductsCart__.empty())
		__UserID__ProductsCart__.clear();
}

void Server::set__UserID__ProductsCart__()
{
	list<User *>::iterator it;
	for (it = usr.begin(); it != usr.end(); it++)
	{
		ShoppingCart *p = new ShoppingCart;
		__UserID__ProductsCart__.insert(pair<int, ShoppingCart *>((*it)->getUserID(), p));
	}
	//throw("undefined");
}

list<Product *> &Server::getProductsList()
{
	return prod;
	//throw("undefined");
}

list<User *> &Server::getUsersList()
{
	return usr;
	//throw("undefined");
}

map<int, ShoppingCart *> Server::get__UserID__ProductsCart__()
{
	return __UserID__ProductsCart__;
	//throw("undefined");
}

bool Server::requestAddProduct(int userID, int productID, int quantity)
{
	if (quantity <= 0)
		return false;
	list<Product *>::iterator it2;
	int nr = 0;
	for (it2 = prod.begin(); it2 != prod.end(); ++it2)
	{
		if ((*it2)->checkQuantity(quantity) && (*it2)->getId() == productID)
		{
			nr++;
			break;
		}
	}
	if (nr == 0)
	{
		return false;
	}
	list<User *>::iterator it1;
	map<int, ShoppingCart *>::iterator iter;
	for (iter = __UserID__ProductsCart__.begin(); iter != __UserID__ProductsCart__.end(); iter++)
	{
		if (iter->first == userID)
		{
			if (iter->second->getQuantity(productID) == 0)
			{
				iter->second->addProduct(productID, quantity);
				for (it2 = prod.begin(); it2 != prod.end(); ++it2)
				{
					if ((*it2)->getId() == productID)
					{
						(*it2)->decreaseQuantity(quantity);
					}
				}
			}
			else
			{
				iter->second->raiseQuantity(productID, quantity);
				for (it2 = prod.begin(); it2 != prod.end(); ++it2)
				{
					if ((*it2)->getId() == productID)
					{
						(*it2)->decreaseQuantity(quantity);
					}
				}
			}
		}
	}
	return true;
	//throw("undefined");
}

bool Server::requestDeleteProduct(int userID, int productID, int quantity)
{
	if (quantity <= 0)
		return false;

	list<User *>::iterator it1;
	int nr = 0;
	for (list<User *>::iterator it = usr.begin(); it != usr.end(); ++it)
	{
		if ((*it)->getUserID() == userID)
		{
			nr++;
			break;
		}
	}
	if (nr == 0)
	{
		return false;
	}
	list<Product *>::iterator it2;
	map<int, ShoppingCart *>::iterator iter;
	for (iter = __UserID__ProductsCart__.begin(); iter != __UserID__ProductsCart__.end(); iter++)
	{
		if (iter->first == userID)
		{
			if (iter->second->getQuantity(productID) <= quantity)
			{
				iter->second->deleteProduct(productID);
				for (it2 = prod.begin(); it2 != prod.end(); it2++)
				{
					if ((*it2)->getId() == productID)
						(*it2)->increaseQuantity(iter->second->getQuantity(productID));
				}
			}
			else
			{
				iter->second->lowerQuantity(productID, quantity);
				for (it2 = prod.begin(); it2 != prod.end(); it2++)
				{
					if ((*it2)->getId() == productID)
						(*it2)->increaseQuantity(quantity);
				}
			}
		}
		else
			return false;
	}
	return true;
	//throw("undefined");
}

/* NU MODIFICATI */
void Server::populateProducts(const json &input)
{
	prod = ObjectFactory::getProductList(input["shoppingCart"]);
}

/* NU MODIFICATI */
void Server::populateUsers(const json &input)
{
	usr = ObjectFactory::getUserList(input["useri"]);
}