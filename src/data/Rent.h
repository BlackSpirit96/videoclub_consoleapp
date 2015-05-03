#ifndef RENT_H_
#define RENT_H_

#include <iostream>
#include <string>

/*
 * class Date
 * used to store date format
 */
class Date
{
public:
	Date() { day = month = year = 0;}
	Date(int d, int m, int y) { day = d; month = m; year = y;}
	int day;
	int month;
	int year;
	int operator-(Date &other);
};

inline int Date::operator -(Date &other)
{
	int days = year * 365 + month * 30 + day;
	int otherdays = other.year * 365 + other.month * 30 + other.day;
	return days - otherdays;
}

inline std::istream& operator>>(std::istream &mystream, Date &mydate)
{
	return mystream>>mydate.day>>mydate.month>>mydate.year;
}

inline std::ostream& operator<<(std::ostream &mystream, Date &mydate)
{
	return mystream<<mydate.day<<' '<<mydate.month<<' '<<mydate.year;
}

/*
 * class Rent
 * used to store rents
 */
class Rent
{
public:
	Rent();
	Rent(int rentNum, std::string customerID, int itemID, Date date, bool vip, bool dvd, std::string type);
    std::string getCustomerID();
    Date getDate();
    int getItemID();
    void setCustomerID(std::string customerID);
    void setDate(Date date);
    void setItemID(int itemID);
    std::string getType();
    bool getVip();
    void setType(std::string type);
    void setVip(bool vip);
    float checkout(Date today); // return the price the customer has to pay for the rent
    bool operator==(int rentNum);
    virtual std::ostream& print(std::ostream& mystream);
    friend std::ostream &operator<<(std::ostream &mystream, Rent &rent);
    virtual std::istream& readData(std::istream &mystream);
    friend std::istream &operator>>(std::istream &mystream, Rent &item);
private:
    int rentID;
	std::string customerID;
	int itemID;
	Date date;
	bool vip;
	bool dvd;
	std::string type;
};

#endif /* RENT_H_ */
