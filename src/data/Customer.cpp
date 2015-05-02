#include "Customer.h"

Customer::Customer()
{
	this->id = "";
	this->firstName = "";
	this->lastName = "";
	this->dateOfBirth = "";
	setGender("other");
	this->address = "";
	this->phoneNumber = "";
	this->vip = 0;
}

Customer::Customer(string id, string firstName, string lastName, string dateOfBirth, string genderText, string address, string phoneNumber, bool vip)
{
	this->id = id;
	this->firstName = firstName;
	this->lastName = lastName;
	this->dateOfBirth = dateOfBirth;
	this->gender = genderText;
	this->address = address;
	this->phoneNumber = phoneNumber;
	this->vip = vip;
}

void Customer::setGender(string genderText)
{
	this->gender = genderText;
}

string Customer::getGender()
{
	return gender;
}

string Customer::getAddress()
{
    return address;
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

void Customer::setAddress(string adress)
{
    this->address = address;
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

bool Customer::operator==(string textID)
{
	return id == textID;
}

ostream& Customer::print(ostream& mystream)
{
	return mystream<<id<<" "<<firstName<<" "<<lastName<<" "<<dateOfBirth<<" "<<getGender()<<" "<<address<<" "<<phoneNumber<<" "<<vip;
}

ostream &operator<<(ostream &mystream, Customer &client)
{
	return client.print(mystream);
}

istream& Customer::readData(istream &mystream)
{
	return mystream>>id>>firstName>>lastName>>dateOfBirth>>gender>>address>>phoneNumber>>vip;
}

istream &operator>>(istream &mystream, Customer &client)
{
	return client.readData(mystream);
}

bool Customer::isVIP()
{
	return vip;
}

void Customer::setVIP(bool vipstate)
{
	vip = vipstate;
}
