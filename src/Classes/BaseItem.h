#ifndef BASEITEM_H_
#define BASEITEM_H_

#include <string>
using namespace std;

class BaseItem
{
public:
	BaseItem(int id, string serial, string title, string genre, int year);
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
private:
	int id;
	string serial;
	string title;
	string genre;
	int year;
};

#endif /* BASEITEM_H_ */
