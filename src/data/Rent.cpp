#include "Rent.h"

Rent::Rent()
{
	this->rentID = 0;
	this->customerID = "";
	this->itemID = 0;
	this->date = Date();
	this->vip = false;
	this->dvd = false;
	setType("game");
}

Rent::Rent(int rentID, std::string customerID, int itemID, Date date, bool vip, bool dvd, std::string type)
{
	this->rentID = rentID;
	this->customerID = customerID;
	this->itemID = itemID;
	this->date = date;
	this->vip = vip;
	this->dvd = dvd;
	this->type = type;
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
    return type;
}

bool Rent::getVip()
{
    return vip;
}

void Rent::setType(std::string type)
{
    this->type = type;
}

void Rent::setVip(bool vip)
{
    this->vip = vip;
}

bool Rent::operator==(int itemNum)
{
	return rentID == itemNum;
}

float Rent::checkout(Date today)
{
	float cost = 0;
	int daydiff = today - date;
	if (type == "game")
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
	else if (type == "drama")
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
	else if (type == "movie")
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
		cost = cost - cost * 0.05;
	}
	return cost;
}

std::ostream& Rent::print(std::ostream& mystream)
{
	return mystream<<rentID<<" "<<customerID<<" "<<itemID<<" "<<date<<" "<<vip<<" "<<dvd<<" "<<type;
}

std::ostream &operator<<(std::ostream &mystream, Rent &rent)
{
	return rent.print(mystream);
}

std::istream& Rent::readData(std::istream &mystream)
{
	return mystream>>rentID>>customerID>>itemID>>date>>vip>>dvd>>type;
}

std::istream &operator>>(std::istream &mystream, Rent &rent)
{
	return rent.readData(mystream);
}
