#ifndef MOVIE_H_
#define MOVIE_H_

#include "../Media.h"

struct time
{
	int hours;
	int minutes;
	int seconds;
};

class Movie: public Media
{
public:
	Movie(int id, string serial, string title, string genre, int year, string director, string actors, bool dvd, struct time duration);
	void setDuration(struct time duration);
	struct time getDuration();
private:
	struct time duration;
};

#endif /* MOVIE_H_ */
