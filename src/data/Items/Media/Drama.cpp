#include "Drama.h"

Drama::Drama()
: Media()
{
	this->episodes.start = 0;
	this->episodes.end = 0;
	this->season = 0;
}

Drama::Drama(int id, string serial, string title, string genre, int year, bool availability, string director, string actors, bool dvd, int season, struct range episodes)
: Media(id, serial, title, genre, year, availability, director, actors, dvd)
{
	this->episodes = episodes;
	this->season = season;
}

struct range Drama::getEpisodes()
{
    return episodes;
}

int Drama::getSeason()
{
    return season;
}

void Drama::setEpisodes(struct range episodes)
{
    this->episodes = episodes;
}

void Drama::setSeason(int season)
{
    this->season = season;
}

ostream& Drama::print(ostream& mystream)
{
	Media::print(mystream);
	mystream<<season<<" "<<episodes;
	return mystream;
}

istream& Drama::readData(istream &mystream)
{
	return Media::readData(mystream)>>season>>episodes;
}
