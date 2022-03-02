#include "User.h"
using namespace std;

User::~User()
{
	//throw("undefined");
}

User::User()
{
	lastName=" ";
	firstName=" ";
	email=" ";
	UserID=0;
	//throw("undefined");
}

User::User(const string &judetf, const string &localitatef, const string &stradaf, int nr_stradaf, const string &blocf, int apartamentf, const string &judetl, const string &localitatel, const string &stradal, int nr_stradal, const string &blocl, int apartamentl, int UserId, const string &lastName, const string &prenume, const string &email)
	: billingData(judetf, localitatef, stradaf, nr_stradaf, blocf, apartamentf),
	  deliveryData(judetl, localitatel, stradal, nr_stradal, blocl, apartamentl)
{
	this->lastName=lastName;
	this->firstName=prenume;
	this->email=email;
	this->UserID=UserId;
	//throw("undefined");
}

User::User(const User &u)
{
	billingData=u.billingData;
	deliveryData=u.deliveryData;
	this->lastName=u.lastName;
	this->firstName=u.firstName;
	this->email=u.email;
	this->UserID=u.UserID;
	//throw("undefined");
}

const User &User::operator=(const User &u)
{
	billingData=u.billingData;
	deliveryData=u.deliveryData;
	this->lastName=u.lastName;
	this->firstName=u.firstName;
	this->email=u.email;
	this->UserID=u.UserID;
	return *this;
	//throw("undefined");
}

void User::setLastName(const string &lastName)
{
	this->lastName=lastName;
	//throw("undefined");
}
void User::setFirstName(const string &firstName)
{
	this->firstName=firstName;
	//throw("undefined");
}
void User::setEmail(const string &email)
{
	this->email=email;
	//throw("undefined");
}
void User::setUserID(int userID)
{
	this->UserID=userID;
	//throw("undefined");
}
void User::setBillingData(const Address &billingData)
{
	this->billingData=billingData;
	//throw("undefined");
}
void User::setDeliveryData(const Address &deliveryData)
{
	this->deliveryData=deliveryData;
	//throw("undefined");
}

string &User::getLastName()
{
	return lastName;
	//throw("undefined");
}
string &User::getFirstName()
{
	return firstName;
	//throw("undefined");
}
string &User::getEmail()
{
	return email;
	//throw("undefined");
}
int User::getUserID() const
{
	return UserID;
	//throw("undefined");
}

Address &User::getBillingData()
{
	return billingData;
	//throw("undefined");
}
Address &User::getDeliveryData()
{
	return deliveryData;
	//throw("undefined");
}

json User::toJSON()
{
	return json(*this);
}
