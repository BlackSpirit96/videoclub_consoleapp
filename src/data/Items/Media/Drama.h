#ifndef DRAMA_H_
#define DRAMA_H_

#include "../Media.h"

/*
 * struct range
 * stores range format
 */
struct range
{
	int start;
	int end;
};

inline ostream &operator<<(ostream &mystream, struct range &item)
{
	return mystream<<item.start<<" "<<item.end;
}

inline istream &operator>>(istream &mystream, struct range &item)
{
	return mystream>>item.start>>item.end;
}

/*
 * class Drama
 * stores Drama item type data
 */
class Drama: public Media
{
public:
	Drama();
	Drama(int id, string serial, string title, string genre, int year, bool availability, string director, string actors, bool dvd, int season, struct range episodes);
    struct range getEpisodes();
    int getSeason();
    void setEpisodes(struct range episodes);
    void setSeason(int season);
    virtual ostream& print(ostream& mystream);
    virtual istream& readData(istream &mystream);
private:
	int season;
	struct range episodes;
};

#endif /* DRAMA_H_ */
