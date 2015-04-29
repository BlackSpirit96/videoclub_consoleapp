#include "Game.h"

Game::Game()
: BaseItem()
{
	this->console = "";
}

Game::Game(int id, string serial, string title, string genre, int year, string console)
: BaseItem(id, serial, title, genre, year)
{
	this->console = console;
}

string Game::getConsole()
{
    return console;
}

void Game::setConsole(string console)
{
    this->console = console;
}

ostream& Game::print(ostream& mystream)
{
	BaseItem::print(mystream);
	mystream<<" "<<console;
	return mystream;
}
