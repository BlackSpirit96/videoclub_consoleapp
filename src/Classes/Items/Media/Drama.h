#ifndef DRAMA_H_
#define DRAMA_H_

#include "../Media.h"

struct range
{
	int start;
	int end;
};

class Drama: public Media
{
public:
	Drama(int id, string serial, string title, string genre, int year, string director, string actors, bool dvd, int season, struct range episodes);
    struct range getEpisodes();
    int getSeason();
    void setEpisodes(struct range episodes);
    void setSeason(int season);
private:
	int season;
	struct range episodes;
};

#endif /* DRAMA_H_ */
