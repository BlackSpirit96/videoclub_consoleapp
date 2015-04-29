#ifndef GAME_H_
#define GAME_H_

#include "../BaseItem.h"
#include <string>

class Game: public BaseItem
{
public:
	Game(int id, string serial, string title, string genre, int year, string console);
    string getConsole();
    void setConsole(string console);
private:
	string console;
};

#endif /* GAME_H_ */