#include "Movie.h"

Movie::Movie()
: Media()
{
	this->duration.hours = 0;
	this->duration.minutes = 0;
	this->duration.seconds = 0;
}

Movie::Movie(int id, string serial, string title, string genre, int year, bool availability, string director, string actors, bool dvd, struct time duration)
: Media(id, serial, title, genre, year, availability, director, actors, dvd)
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

ostream& Movie::print(ostream& mystream)
{
	Media::print(mystream);
	mystream<<" "<<duration;
	return mystream;
}
