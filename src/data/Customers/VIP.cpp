#include "VIP.h"

VIP::VIP()
: Customer()
{
	this->vip = false;
	this->credidCardNumber = "";
	this->issuingNetwork = "";
	this->cvv = 0;
}

VIP::VIP(string id, string firstName,
		string lastName, string dateOfBirth,
		string genderText, string adress,
		string phoneNumber, bool vip, string credidCardNumber,
		string issuingNetwork, int cvv) : Customer(id, firstName, lastName, dateOfBirth, genderText, adress, phoneNumber)
{
	this->vip = vip;
	this->credidCardNumber = credidCardNumber;
	this->issuingNetwork = issuingNetwork;
	this->cvv = cvv;
}

string VIP::getCredidCardNumber()
{
    return credidCardNumber;
}

int VIP::getCvv()
{
    return cvv;
}

string VIP::getIssuingNetwork()
{
    return issuingNetwork;
}

void VIP::setCredidCardNumber(string credidCardNumber)
{
    this->credidCardNumber = credidCardNumber;
}

void VIP::setCvv(int cvv)
{
    this->cvv = cvv;
}

void VIP::setIssuingNetwork(string issuingNetwork)
{
    this->issuingNetwork = issuingNetwork;
}

ostream& VIP::print(ostream& mystream)
{
	Customer::print(mystream);
	mystream<<" "<<vip<<" "<<credidCardNumber<<" "<<issuingNetwork<<" "<<cvv;
	return mystream;
}

istream& VIP::readData(istream &mystream)
{
	return Customer::readData(mystream)>>vip>>credidCardNumber>>issuingNetwork>>cvv;
}

bool VIP::isVIP()
{
	return vip;
}

void VIP::setVIP(bool vip)
{
	this->vip = vip;
}

