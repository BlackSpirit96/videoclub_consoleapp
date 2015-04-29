#ifndef MOVIE_H_
#define MOVIE_H_

#include "../Media.h"

struct time
{
	int hours;
	int minutes;
	int seconds;
};

inline ostream &operator<<(ostream &mystream, struct time &item)
{
	return mystream<<item.hours<<":"<<item.minutes<<":"<<item.seconds;
}

inline istream &operator>>(istream &mystream, struct time &item)
{
	return mystream>>item.hours>>item.minutes>>item.seconds;
}

class Movie: public Media
{
public:
	Movie();
	Movie(int id, string serial, string title, string genre, int year, string director, string actors, bool dvd, struct time duration);
	void setDuration(struct time duration);
	struct time getDuration();
	virtual ostream& print(ostream& mystream);
private:
	struct time duration;
};

#endif /* MOVIE_H_ */
