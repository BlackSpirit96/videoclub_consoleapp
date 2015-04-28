#ifndef MEDIA_H_
#define MEDIA_H_

#include "../BaseItem.h"
#include <string>

class Media: public BaseItem
{
public:
	Media(int id, string serial, string title, string genre, int year, string director, string actors, bool dvd);
    string getActors();
    string getDirector();
    bool isDvd();
    void setActors(string actors);
    void setDirector(string director);
    void setDvd(bool dvd);
private:
	string director;
	string actors;
	bool dvd;
};

#endif /* MEDIA_H_ */
