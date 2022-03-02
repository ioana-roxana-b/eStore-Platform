#include "Address.h"

using namespace std;

Address::Address()
{
    county=" ";
    locality=" ";
    street=" ";
    number=0;
    block=" ";
    apartment=0;
	//throw("undefined");
}

Address::Address(const Address &address)
{
    this->county=address.county;
    this->locality=address.locality;
    this->street=address.street;
    this->number=address.number;
    this->block=address.block;
    this->apartment=address.apartment;
	//throw("undefined");
}

Address::Address(const string &jud, const string &loc, const string &str, int nr, const string &bl, int ap)
{
    this->county=jud;
    this->locality=loc;
    this->street=str;
    this->number=nr;
    this->block=bl;
    this->apartment=ap;
	//throw("undefined");
}

const Address &Address::operator=(const Address &adr)
{
    this->county=adr.county;
    this->locality=adr.locality;
    this->street=adr.street;
    this->number=adr.number;
    this->block=adr.block;
    this->apartment=adr.apartment;
    return *this;
	//throw("undefined");
}

void Address::setStrada(const string &str)
{
    this->street=str;
	//throw("undefined");
}

void Address::setNumber(int nr)
{
    this->number=nr;
	//throw("undefined");
}

void Address::setBlock(const string &bl)
{
    this->block=bl;
	//throw("undefined");
}

void Address::setApartment(int ap)
{
    this->apartment=ap;
	//throw("undefined");
}

void Address::setCounty(const string &jud)
{
    this->county=jud;
	//throw("undefined");
}

void Address::setLocality(const string &loc)
{
    this->locality=loc;
	//throw("undefined");
}

string &Address::getStreet()
{
    return street;
	//throw("undefined");
}

int Address::getNumber()
{
    return number;
	//throw("undefined");
}
string &Address::getBlock()
{
    return block;
	//throw("undefined");
}

int Address::getApartment()
{
    return apartment;
	//throw("undefined");
}

string &Address::getCounty()
{
    return county;
	//throw("undefined");
}

string &Address::getLocality()
{
    return locality;
	//throw("undefined");
}

bool Address::operator==(const Address &address)
{
    return (locality==address.locality && county==address.county && apartment==address.apartment && block==address.block && number==address.number && street==address.street);
	//throw("undefined");
}

bool Address::operator!=(const Address &address)
{
    return (locality!=address.locality && county!=address.county && apartment!=address.apartment && block!=address.block && number!=address.number && street!=address.street);
	//throw("undefined");
}

ostream &operator<<(ostream &os, const Address &a)
{
    os<<a.locality;
    os<<a.county;
    os<<a.apartment;
    os<<a.block;
    os<<a.number;
    os<<a.street;
    return os;
	//throw("undefined");
}

json Address::toJSON()
{
	return json(*this);
}