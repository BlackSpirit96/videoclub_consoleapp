#include "Movie.h"

Movie::Movie(int id, string serial, string title, string genre, int year, string director, string actors, bool dvd, struct time duration)
: Media(id, serial, title, genre, year, director, actors, dvd)
{
	this->duration = duration;
}

void Movie::setDuration(struct time duration)
{
	this->duration = duration;
}

struct time Movie::getDuration()
{
	return duration;
}
