#ifndef RENT_H_
#define RENT_H_

#include <iostream>
#include <string>

class Date
{
public:
	Date() { day = month = year = 0;}
	Date(int d, int m, int y) { day = d; month = m; year = y;}
	int day;
	int month;
	int year;
};

inline std::istream& operator>>(std::istream &mystream, Date &mydate)
{
	return mystream>>mydate.day>>mydate.month>>mydate.year;
}

inline std::ostream& operator<<(std::ostream &mystream, Date &mydate)
{
	return mystream<<mydate.day<<'/'<<mydate.month<<'/'<<mydate.year;
}

class Rent
{
public:
	Rent();
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
    int checkout();
    bool operator==(std::string itemText);
    virtual std::ostream& print(std::ostream& mystream);
    friend std::ostream &operator<<(std::ostream &mystream, Rent &rent);
private:
	std::string customerID;
	std::string itemSerial;
	Date date;
	bool vip;
	char type;
};

#endif /* RENT_H_ */
