#include "Rent.h"

Rent::Rent()
{
	this->customerID = "";
	this->itemID = 0;
	this->date = Date();
	this->vip = false;
	setType("game");
}

Rent::Rent(std::string customerID, int itemID, Date date, bool vip, bool dvd, std::string type)
{
	this->customerID = customerID;
	this->itemID = itemID;
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

int Rent::getItemID()
{
    return itemID;
}

void Rent::setCustomerID(std::string customerID)
{
    this->customerID = customerID;
}

void Rent::setDate(Date date)
{
    this->date = date;
}

void Rent::setItemID(int itemID)
{
    this->itemID = itemID;
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

bool Rent::operator==(int itemNum)
{
	return itemID == itemNum;
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
	return mystream<<customerID<<" "<<itemID<<" "<<date<<" "<<vip<<" "<<getType();
}

std::ostream &operator<<(std::ostream &mystream, Rent &rent)
{
	return rent.print(mystream);
}
