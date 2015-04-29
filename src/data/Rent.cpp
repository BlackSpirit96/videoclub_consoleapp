#include "Rent.h"

Rent::Rent(std::string customerID, std::string itemSerial, Date date, bool vip, std::string type)
{
	this->customerID = customerID;
	this->itemSerial = itemSerial;
	this->date = date;
	this->vip = vip;
	setType(type);
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

std::string Rent::getType()
{
    if (type == 'g')
    	return "Game";
    else if (type == 'm')
    	return "Movie";
    else
    	return "Drama";
}

bool Rent::getVip()
{
    return vip;
}

void Rent::setType(std::string type)
{
    if (type == "game")
    {
    	this->type = 'g';
    }
    else if (type == "movie")
    {
    	this->type = 'm';
    }
    else
    {
    	this->type = 'd';
    }
}

void Rent::setVip(bool vip)
{
    this->vip = vip;
}
