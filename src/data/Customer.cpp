#include "Customer.h"

Customer::Customer(string id, string firstName, string lastName, string dateOfBirth, string genderText, string adress, string phoneNumber)
{
	this->id = id;
	this->firstName = firstName;
	this->lastName = lastName;
	this->dateOfBirth = dateOfBirth;
	setGender(genderText);
	this->adress = adress;
	this->phoneNumber = phoneNumber;
}

void Customer::setGender(string genderText)
{
	if (genderText == "male")
	{
		this->gender = 'm';
	}
	else if (genderText == "female")
	{
		this->gender = 'f';
	}
	else
	{
		this->gender = 'o';
	}
}

string Customer::getGender()
{
	if (this->gender == 'm')
	{
		return "male";
	}
	else if (this->gender == 'f')
	{
		return "female";
	}
	else
	{
		return "other";
	}
}

string Customer::getAdress()
{
    return adress;
}

string Customer::getDateOfBirth()
{
    return dateOfBirth;
}

string Customer::getFirstName()
{
    return firstName;
}

string Customer::getId()
{
    return id;
}

string Customer::getLastName()
{
    return lastName;
}

string Customer::getPhoneNumber()
{
    return phoneNumber;
}

void Customer::setAdress(string adress)
{
    this->adress = adress;
}

void Customer::setDateOfBirth(string dateOfBirth)
{
    this->dateOfBirth = dateOfBirth;
}

void Customer::setFirstName(string firstName)
{
    this->firstName = firstName;
}

void Customer::setId(string id)
{
    this->id = id;
}

void Customer::setLastName(string lastName)
{
    this->lastName = lastName;
}

void Customer::setPhoneNumber(string phoneNumber)
{
    this->phoneNumber = phoneNumber;
}


