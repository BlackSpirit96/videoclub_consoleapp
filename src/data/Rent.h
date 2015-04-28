#ifndef RENT_H_
#define RENT_H_

#include <iostream>
#include <string>

struct Date
{
	int day;
	int month;
	int year;
};

class Rent
{
public:
	Rent(std::string customerID, std::string itemSerial, Date date);
    std::string getCustomerID();
    Date getDate();
    string getItemSerial();
    void setCustomerID(string customerID);
    void setDate(Date date);
    void setItemSerial(string itemSerial);
private:
	std::string customerID;
	std::string itemSerial;
	Date date;
};

#endif /* RENT_H_ */
