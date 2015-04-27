#include "Media.h"

Media::Media(int id, string serial, string title, string genre, int year, string director, string actors, bool dvd)
: BaseItem(id, serial, title, genre, year)
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


