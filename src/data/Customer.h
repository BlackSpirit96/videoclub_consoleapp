#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <string>
#include <iostream>

using namespace std;

class Customer
{
public:
	Customer();
	Customer(string id, string firstName, string lastName, string dateOfBirth, string genderText, string address, string phoneNumber, bool vip);
    string getAddress();
    string getDateOfBirth();
    string getFirstName();
	string getGender();
    string getId();
    string getLastName();
    string getPhoneNumber();
    void setAddress(string address);
    void setDateOfBirth(string dateOfBirth);
    void setFirstName(string firstName);
    void setGender(string genderText);
    void setId(string id);
    void setLastName(string lastName);
    void setPhoneNumber(string phoneNumber);
	virtual bool isVIP() { return vip;}
	bool operator==(string textID);
	virtual ostream& print(ostream& mystream);
	friend ostream &operator<<(ostream &mystream, Customer &client);
	virtual istream& readData(istream &mystream);
	friend istream &operator>>(istream &mystream, Customer &item);
private:
	string id;
	string firstName;
	string lastName;
	string dateOfBirth;
	string gender;
	string address;
	string phoneNumber;
	bool vip;
};

#endif /* CUSTOMER_H_ */
