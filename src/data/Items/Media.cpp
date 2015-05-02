#include "Media.h"

Media::Media()
: BaseItem()
{
	this->director = "";
	this->actors = "";
	this->dvd = false;
}

Media::Media(int id, string serial, string title, string genre, int year, bool availability, string director, string actors, bool dvd)
: BaseItem(id, serial, title, genre, year, availability)
{
	this->director = director;
	this->actors = actors;
	this->dvd = dvd;
}

string Media::getActors()
{
    return actors;
}

string Media::getDirector()
{
    return director;
}

bool Media::isDvd()
{
    return dvd;
}

void Media::setActors(string actors)
{
    this->actors = actors;
}

void Media::setDirector(string director)
{
    this->director = director;
}

void Media::setDvd(bool dvd)
{
    this->dvd = dvd;
}

ostream& Media::print(ostream& mystream)
{
	BaseItem::print(mystream);
	mystream<<" "<<director<<" "<<actors<<" "<<dvd;
	return mystream;
}

istream& Media::readData(istream &mystream)
{
	return BaseItem::readData(mystream)>>director>>actors>>dvd;
}
