#include "Rent.h"

Rent::Rent()
{
	this->customerID = "";
	this->itemSerial = "";
	this->date = Date();
	this->vip = false;
	setType("game");
}

Rent::Rent(std::string customerID, std::string itemSerial, Date date, bool vip, bool dvd, std::string type)
{
	this->customerID = customerID;
	this->itemSerial = itemSerial;
	this->date = date;
	this->vip = vip;
	this->dvd = dvd;
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

bool Rent::operator==(std::string itemText)
{
	return itemSerial == itemText;
}

float Rent::checkout(Date today)
{
	float cost = 0;
	int daydiff = today - date;
	if (type == 'g')
	{
		if ( daydiff <= 2)
		{
			cost = 3.0;
		}
		else
		{
			cost = 3 + (daydiff - 2);
		}
	}
	else if (type == 'd')
	{
		if (daydiff <= 3)
		{
			cost = 2.0;
		}
		else
		{
			cost = 2.0 + (daydiff - 3) * 0.5;
		}
		if (!dvd)
		{
			cost += 1;
		}
	}
	else if (type == 'm')
	{
		if (!dvd)
		{
			cost = daydiff * 2.0;
		}
		else
		{
			if (daydiff <= 3 )
			{
				cost = 1.0;
			}
			else
			{
				cost = 1.0 + (daydiff - 3) * 0.5;
			}
		}
		if (today.year == date.year)
		{
			cost += cost * 0.5;
		}
	}
	if (vip)
	{
		cost -= cost * 0.05;
	}
	return cost;
}

std::ostream& Rent::print(std::ostream& mystream)
{
	return mystream<<customerID<<" "<<itemSerial<<" "<<date<<" "<<vip<<" "<<getType();
}

std::ostream &operator<<(std::ostream &mystream, Rent &rent)
{
	return rent.print(mystream);
}
