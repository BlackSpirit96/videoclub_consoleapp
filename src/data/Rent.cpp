#include "Rent.h"

Rent::Rent(std::string customerID, std::string itemSerial, Date date)
{
	this->customerID = customerID;
	this->itemSerial = itemSerial;
	this->date = date;
}

std::string Rent::getCustomerID()
{
    return customerID;
}

Date Rent::getDate()
{
    return date;
}

std::string Rent::getItemSerial()
{
    return itemSerial;
}

void Rent::setCustomerID(std::string customerID)
{
    this->customerID = customerID;
}

void Rent::setDate(Date date)
{
    this->date = date;
}

void Rent::setItemSerial(std::string itemSerial)
{
    this->itemSerial = itemSerial;
}


