#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <string>
using namespace std;

class Customer
{
public:
	Customer(string id, string firstName, string lastName, string dateOfBirth, string genderText, string adress, string phoneNumber);
    string getAdress();
    string getDateOfBirth();
    string getFirstName();
	string getGender();
    string getId();
    string getLastName();
    string getPhoneNumber();
    void setAdress(string adress);
    void setDateOfBirth(string dateOfBirth);
    void setFirstName(string firstName);
    void setGender(string genderText);
    void setId(string id);
    void setLastName(string lastName);
    void setPhoneNumber(string phoneNumber);
	bool isVIP() { return false;}
private:
	string id;
	string firstName;
	string lastName;
	string dateOfBirth;
	char gender;
	string adress;
	string phoneNumber;
};

#endif /* CUSTOMER_H_ */
