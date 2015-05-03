#ifndef GAME_H_
#define GAME_H_

#include "../BaseItem.h"
#include <string>

/*
 * class Game
 * stores Game item data
 */
class Game: public BaseItem
{
public:
	Game();
	Game(int id, string serial, string title, string genre, int year, bool availability, string console);
    string getConsole();
    void setConsole(string console);
    ostream& print(ostream& mystream);
private:
	string console;
};

#endif /* GAME_H_ */
