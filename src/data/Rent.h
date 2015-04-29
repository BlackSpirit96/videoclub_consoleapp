#ifndef RENT_H_
#define RENT_H_

#include <iostream>
#include <string>

class Date
{
public:
	int day;
	int month;
	int year;
};

class Rent
{
public:
	Rent(std::string customerID, std::string itemSerial, Date date, bool vip, std::string type);
    std::string getCustomerID();
    Date getDate();
    std::string getItemSerial();
    void setCustomerID(std::string customerID);
    void setDate(Date date);
    void setItemSerial(std::string itemSerial);
    std::string getType();
    bool getVip();
    void setType(std::string type);
    void setVip(bool vip);
private:
	std::string customerID;
	std::string itemSerial;
	Date date;
	bool vip;
	char type;
};

#endif /* RENT_H_ */
