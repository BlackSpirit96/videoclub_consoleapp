#include "Drama.h"

Drama::Drama(int id, string serial, string title, string genre, int year, string director, string actors, bool dvd, int season, struct range episodes)
: Media(id, serial, title, genre, year, director, actors, dvd)
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


