#include "VIP.h"

VIP::VIP(string id, string firstName,
		string lastName, string dateOfBirth,
		string genderText, string adress,
		int phoneNumber, string credidCardNumber,
		string issuingNetwork, int cvv) : Customer(id, firstName, lastName, dateOfBirth, genderText, adress, phoneNumber)
{
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


