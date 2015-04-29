#ifndef BASEITEM_H_
#define BASEITEM_H_

#include <string>
#include <iostream>
using namespace std;

class BaseItem
{
public:
	BaseItem(int id, string serial, string title, string genre, int year);
	BaseItem();
    string getGenre();
    int getId();
    string getSerial();
    string getTitle();
    int getYear();
    void setGenre(string genre);
    void setId(int id);
    void setSerial(string serial);
    void setTitle(string title);
    void setYear(int year);
    virtual ostream& print(ostream& mystream);
    friend ostream &operator<<(ostream &mystream, BaseItem &item);
    bool operator==(int number);
    bool operator==(string text);
private:
    int id;
	string serial;
	string title;
	string genre;
	int year;
};

#endif /* BASEITEM_H_ */
