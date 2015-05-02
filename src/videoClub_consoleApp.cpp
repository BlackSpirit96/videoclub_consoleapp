#include <iostream>
#include <fstream>
#include <sstream>

//dataClasses
#include "data/Rent.h"

#include "data/Customer.h"
#include "data/Customers/VIP.h"

#include "data/Items/Game.h"
#include "data/Items/Media/Movie.h"
#include "data/Items/Media/Drama.h"
//other
#include "dynamicArray.h"

using namespace std;

Date TODAY_DAY;

void loadData(DynamicArray<VIP> &customers, DynamicArray<Game> &games, DynamicArray<Movie> &movies, DynamicArray<Drama> &drama, DynamicArray<Rent> &rents)
{
	ifstream customersFile("customers.txt");
	ifstream customersVIPFile("customersvip.txt");
	ifstream gamesFile("games.txt");
	ifstream moviesFile("movies.txt");
	ifstream dramaFile("drama.txt");
	ifstream rentsFile("rents.txt");
	string temp;

	while (getline(customersFile, temp))
	{
		istringstream line_stream(temp);
		VIP newCust;
		line_stream>>newCust;
		customers.insert(newCust);
	}

	while (getline(gamesFile, temp))
	{
		istringstream line_stream(temp);
		Game newGame;
		line_stream>>newGame;
		games.insert(newGame);
	}

	while(getline(moviesFile, temp))
	{
		istringstream line_stream(temp);
		Movie newMovie;
		line_stream>>newMovie;
		movies.insert(newMovie);
	}

	while(getline(dramaFile, temp))
	{
		istringstream line_stream(temp);
		Drama newDrama;
		line_stream>>newDrama;
		drama.insert(newDrama);
	}

	while(getline(rentsFile, temp))
	{
		istringstream line_stream(temp);
		Rent newRent;
		line_stream>>newRent;
		rents.insert(newRent);
	}
}

template <class T>
void getInput(string message, T &thing)
{
	cout<<message;
    if ( !(cin>>thing) )
    {
      cin.clear();
      cin.ignore();
      cout << "Incorrect entry. Try again: ";
    }
}

void convertSpaces(string &text)
{
	for (unsigned int i = 0; i < text.length(); i++)
	{
		if(text[i] == ' ')
			text[i] = '_';
	}
}

void toLower(string &text)
{
	for (unsigned int i = 0; i < text.length(); i++)
	{
			text[i] = tolower(text[i]);
	}
}

void getLine(string message, string &returnStr)
{
	cout<<message;
	cin.ignore();
	if (!getline(cin, returnStr))
	{
		cin.clear();
		cin.ignore();
		cout << "Incorrect entry. Try again: ";
	}
	convertSpaces(returnStr);
}

bool getInput(string message)
{
	char choice;
	cout<<message;
	do
	{
		cin.get(choice);
		choice = tolower(choice);
	} while (choice != 'y' && choice != 'n');
	if (choice == 'y')
		return true;
	else
		return false;
}

void insertGame(DynamicArray<Game> &games)
{
	int id, year;
	string serial, title, genre, console;
	getInput("Enter game id: ", id);
	getLine("Enter game title: ", title);
	getInput("Enter game serial: ", serial);
	getInput("Enter game genre: ", genre);
	getInput("Enter game console type: ", console);
	getInput("Enter game production year: ", year);
	Game newGame(id, serial, title, genre, year, true, console);
	games.insert(newGame);
}

void insertMovie(DynamicArray<Movie> &movies)
{
	int id, year;
	string serial, title, genre, director, actors;
	bool dvd;
	struct time duration;
	getInput("Enter movie id : ", id);
	getInput("Enter movie serial : ", serial);
	getLine("Enter movie title : ", title);
	getInput("Enter movie genre : ", genre);
	getInput("Enter movie year : ", year);
	getLine("Enter movie director : ", director);
	getLine("Enter movie actors : ", actors);
	dvd = getInput("Is movie in dvd form ?<y/n>");
	getInput("Enter movie duration (hour min sec) : ", duration);
	movies.insert(Movie(id,serial, title, genre, year, true, director, actors, dvd, duration));
	return;
}

void insertDrama(DynamicArray<Drama> &drama)
{
	int id, year, season;
	string serial, title, genre, director, actors;
	struct range episodes;
	bool dvd;
	getInput("Enter drama id : ", id);
	getInput("Enter drama serial : ", serial);
	getLine("Enter drama title : ", title);
	getInput("Enter drama genre : ", genre);
	getInput("Enter drama year : ", year);
	getLine("Enter drama director : ", director);
	getLine("Enter drama actors : ", actors);
	dvd = getInput("Is drama in dvd form ?<y/n>");
	getInput("Enter drama season: ", season);
	getInput("Enter drama episode rage(start stop): ", episodes);
	drama.insert(Drama(id, serial, title, genre, year, true, director, actors, dvd, season, episodes));
}

template <typename A, class B, class C>
void showAvailable(A id, B &list, C type)
{
	C *table;
	int tableSize = 0;
	list.returnSearch(id, table, tableSize);
	for (int i = 0; i < tableSize; i++)
	{
		if (table[i].isAvailable())
			cout<<table[i];
	}
	return;
}

void gamesMenu(DynamicArray<Game> &games)
{
	char choice;
	while (true)
	{
		cout<<"======< Games Menu >======"<<endl;
		cout<<" [1] Show games"<<endl;
		cout<<" [2] Add games"<<endl;
		cout<<" [3] Update game"<<endl;
		cout<<" [4] Remove game"<<endl;
		cout<<" [5] Search available game"<<endl;
		cout<<" [Q] Main Menu"<<endl;
		getInput("", choice);
		choice = tolower(choice);
		if (choice == '1')
		{
			cout<<"======< Games List >======"<<endl;
			games.print();
		}
		else if (choice == '2')
		{
			cout<<"======< New Game >======"<<endl;
			insertGame(games);
		}
		else if (choice == '3')
		{
			int id;
			cout<<"======< Game Update >======"<<endl;
			getInput("Enter game id: ", id);
			games.printSearch(id);
			games.remove(id);
			cout<<"Enter new game data."<<endl;
			insertGame(games);
		}
		else if (choice == '4')
		{
			int id;
			cout<<"======< Game Remove >======"<<endl;
			getInput("Enter game id: ", id);
			games.remove(id);
		}
		else if (choice == '5')
		{
			int id = 0;
			string text;
			cout<<"======< Games Availability Search >======"<<endl;
			bool goString = getInput("Search for title ?<y/n>");
			if (goString)
			{
				string term;
				getInput("Enter game title: ", term);
			}
			else
			{
				int term;
				getInput("Enter game id: ", term);
			}
			cout<<"======< Search Result >======"<<endl;
			if (goString)
			{
				showAvailable(text, games, Game());
			}
			else
			{
				showAvailable(id, games, Game());
			}
		}
		else if (choice == 'q')
			break;
	}
}

void moviesMenu(DynamicArray<Movie> &movies)
{
	char choice;
	while (true)
	{
		cout<<"======< Movies Menu >======"<<endl;
		cout<<" [1] Show movies"<<endl;
		cout<<" [2] Add movies"<<endl;
		cout<<" [3] Update movie"<<endl;
		cout<<" [4] Remove movie"<<endl;
		cout<<" [5] Search available movie"<<endl;
		cout<<" [Q] Main Menu"<<endl;
		getInput("", choice);
		choice = tolower(choice);
		if (choice == '1')
		{
			cout<<"======< Movies List >======"<<endl;
			movies.print();
		}
		else if (choice == '2')
		{
			cout<<"======< New movie >======"<<endl;
			insertMovie(movies);
		}
		else if (choice == '3')
		{
			int id;
			cout<<"======< Movie Update >======"<<endl;
			getInput("Enter movie id: ", id);
			movies.printSearch(id);
			movies.remove(id);
			cout<<"Enter new movie data."<<endl;
			insertMovie(movies);
		}
		else if (choice == '4')
		{
			int id;
			cout<<"======< Movie Remove >======"<<endl;
			getInput("Enter movie id: ", id);
			movies.remove(id);
		}
		else if (choice == '5')
		{
			int id = 0;
			string text;
			cout<<"======< Movies Availability Search >======"<<endl;
			bool goString = getInput("Search for title ?<y/n>");
			if (goString)
			{
				string term;
				getInput("Enter movie title: ", term);
			}
			else
			{
				int term;
				getInput("Enter movie id: ", term);
			}
			cout<<"======< Search Result >======"<<endl;
			if (goString)
			{
				showAvailable(text, movies, Movie());
			}
			else
			{
				showAvailable(id, movies, Movie());
			}
		}
		else if (choice == 'q')
			break;
	}
}

void dramaMenu(DynamicArray<Drama> &drama)
{
	char choice;
	while (true)
	{
		cout<<"======< Drama Menu >======"<<endl;
		cout<<" [1] Show drama"<<endl;
		cout<<" [2] Add drama"<<endl;
		cout<<" [3] Update drama"<<endl;
		cout<<" [4] Remove drama"<<endl;
		cout<<" [5] Search available drama"<<endl;
		cout<<" [Q] Main Menu"<<endl;
		getInput("", choice);
		choice = tolower(choice);
		if (choice == '1')
		{
			cout<<"======< Drama List >======"<<endl;
			drama.print();
		}
		else if (choice == '2')
		{
			cout<<"======< New drama >======"<<endl;
			insertDrama(drama);
		}
		else if (choice == '3')
		{
			int id;
			cout<<"======< Drama Update >======"<<endl;
			getInput("Enter drama id: ", id);
			drama.printSearch(id);
			drama.remove(id);
			cout<<"Enter new drama data."<<endl;
			insertDrama(drama);
		}
		else if (choice == '4')
		{
			int id;
			cout<<"======< Drama Remove >======"<<endl;
			getInput("Enter drama id: ", id);
			drama.remove(id);
		}
		else if (choice == '5')
		{
			int id = 0;
			string text;
			cout<<"======< Drama Availability Search >======"<<endl;
			bool goString = getInput("Search for title ?<y/n>");
			if (goString)
			{
				string term;
				getInput("Enter drama title: ", term);
			}
			else
			{
				int term;
				getInput("Enter drama id: ", term);
			}
			cout<<"======< Search Result >======"<<endl;
			if (goString)
			{
				showAvailable(text, drama, Drama());
			}
			else
			{
				showAvailable(id, drama, Drama());
			}
		}
		else if (choice == 'q')
			break;
	}
}

void itemMenu(DynamicArray<Game> &games, DynamicArray<Movie> &movies, DynamicArray<Drama> &drama)
{
	char choice;
	while(true)
	{
		cout<<"======< Item Menu >======"<<endl;
		cout<<" [1] Games management"<<endl;
		cout<<" [2] Movie management"<<endl;
		cout<<" [3] Series management"<<endl;
		cout<<" [Q] Main Menu"<<endl;
		getInput("", choice);
		choice = tolower(choice);
		if (choice == '1')
			gamesMenu(games);
		else if (choice == '2')
			moviesMenu(movies);
		else if (choice == '3')
			dramaMenu(drama);
		else if (choice == 'q')
			break;
	}
}

void insertCustomer(DynamicArray<VIP> &customers)
{
	string id, firstName, lastName, dateOfBirth, gender, address, phoneNumber;
	string creditCardNumber, issuingNetwork;
	int cvv;
	bool vip;
	getInput("Enter id number: ", id);
	getInput("Enter fistname: ", firstName);
	getInput("Enter lastname: ", lastName);
	getInput("Enter date of birth: ", dateOfBirth); // getline
	getInput("Enter gender: ", gender);
	toLower(gender);
	getInput("Enter address: ", address);
	getInput("Enter phone number: ", phoneNumber);
	vip = getInput("Is the customer a VIP one ?<y/n>");
	if(vip)
	{
		getInput("Enter cradit card number: ", creditCardNumber);
		getInput("Enter credit card issuing network: ", issuingNetwork);
		getInput("Enter cradit card cvv number: ", cvv);
		customers.insert(VIP(id, firstName, lastName, dateOfBirth, gender, address, phoneNumber, true, creditCardNumber, issuingNetwork, cvv));
	}
	else
	{
		customers.insert(VIP(id, firstName, lastName, dateOfBirth, gender, address, phoneNumber, false, "", "", 0));
	}
}

void customerMenu(DynamicArray<VIP> &customers)
{
	while(true)
	{
		char choice;
		cout<<"======< Customer Menu >======"<<endl;
		cout<<" [1] Show customers"<<endl;
		cout<<" [2] Add customer"<<endl;
		cout<<" [3] Update customer"<<endl;
		cout<<" [4] Remove customer"<<endl;
		cout<<" [Q] Main Menu"<<endl;
		getInput("", choice);
		choice = tolower(choice);
		if (choice == '1')
		{
			cout<<"======< Customers List >======"<<endl;
			customers.print();
		}
		else if (choice == '2')
		{
			cout<<"======< New Customer >======"<<endl;
			insertCustomer(customers);
		}
		else if (choice == '3')
		{
			string id;
			cout<<"======< Customer Update >======"<<endl;
			getInput("Enter customer id: ", id);
			customers.printSearch(id);
			customers.remove(id);
			cout<<"Enter new customer data."<<endl;
			insertCustomer(customers);
		}
		else if (choice == '4')
		{
			string id;
			cout<<"======< Customer Remove >======"<<endl;
			getInput("Enter customer id: ", id);
			customers.remove(id);
		}
		else if (choice == 'q')
			break;
	}
}

void rentMenu(DynamicArray<VIP> &customers, DynamicArray<Game> &games, DynamicArray<Movie> &movies, DynamicArray<Drama> &drama, DynamicArray<Rent> &rents)
{
	int itemID;
	string customerID;
	char choice;
	while(true)
	{
		cout<<"======< Rent Menu >======"<<endl;
		cout<<" [1] Rent a game"<<endl;
		cout<<" [2] Rent a movie"<<endl;
		cout<<" [3] Rent a drama"<<endl;
		cout<<" [4] Checkout rent"<<endl;
		cout<<" [Q] Main Menu"<<endl;
		getInput("", choice);
		choice = tolower(choice);
		if (choice == '1')
		{
			getInput("Enter customer id: ", customerID);
			getInput("Enter item serial number: ", itemID);
			rents.insert(Rent(customerID, itemID, TODAY_DAY, customers.search(customerID)->isVIP(), false, "game"));
			games.search(itemID)->setAvailability(false);
		}
		else if (choice == '2')
		{
			getInput("Enter customer id: ", customerID);
			getInput("Enter item serial number: ", itemID);
			rents.insert(Rent(customerID, itemID, TODAY_DAY, customers.search(customerID)->isVIP(), movies.search(itemID)->isDvd(), "movie"));
			movies.search(itemID)->setAvailability(false);
		}
		else if (choice == '3')
		{
			getInput("Enter customer id: ", customerID);
			getInput("Enter item serial number: ", itemID);
			rents.insert(Rent(customerID, itemID, TODAY_DAY, customers.search(customerID)->isVIP(), drama.search(itemID)->isDvd(), "drama"));
			drama.search(itemID)->setAvailability(false);
		}
		else if (choice == '4')
		{
			int itemID;
			getInput("Enter item: ", itemID);
			Rent *current = rents.search(itemID);
			cout<<"Checkout: "<<current->checkout(TODAY_DAY)<<endl;
			if (current->getType() == "game")
			{
				games.search(current->getItemID())->setAvailability(true);
			}
			else if (current->getType() == "movie")
			{
				movies.search(current->getItemID())->setAvailability(true);
			}
			else
			{
				drama.search(current->getItemID())->setAvailability(true);
			}
			rents.remove(itemID);
		}
		else if (choice == 'q')
		{
			break;
		}
	}
}

void mainMenu(DynamicArray<VIP> &customers, DynamicArray<Game> &games, DynamicArray<Movie> &movies, DynamicArray<Drama> &drama, DynamicArray<Rent> &rents)
{
	char choice;
	while(true)
	{
		cout<<"======< Main Menu >======"<<endl;
		cout<<" [1] Item management"<<endl;
		cout<<" [2] Customer management"<<endl;
		cout<<" [3] Rent management"<<endl;
		cout<<" [Q] Save & Quit"<<endl;
		getInput("", choice);
		choice = tolower(choice);
		if (choice == '1')
			itemMenu(games, movies, drama);
		else if (choice == '2')
			customerMenu(customers);
		else if (choice == '3')
			rentMenu(customers, games, movies, drama, rents);
		else if (choice == 'q')
			break;
	}
}

void saveData(DynamicArray<VIP> &customers, DynamicArray<Game> &games, DynamicArray<Movie> &movies, DynamicArray<Drama> &drama, DynamicArray<Rent> &rents)
{
	ofstream customersFile("customers.txt");
	ofstream gamesFile("games.txt");
	ofstream moviesFile("movies.txt");
	ofstream dramaFile("drama.txt");
	ofstream rentsFile("rents.txt");
	customers.outputData(customersFile);
	games.outputData(gamesFile);
	movies.outputData(moviesFile);
	drama.outputData(dramaFile);
	rents.outputData(rentsFile);
}

int main() {
	cout<<"Enter today date(day month year): ";
	getInput("", TODAY_DAY);
	DynamicArray<VIP> customers(100);
	DynamicArray<Game> games(100);
	DynamicArray<Movie> movies(100);
	DynamicArray<Drama> drama(100);
	DynamicArray<Rent> rents(100);
	loadData(customers, games, movies, drama, rents);
	mainMenu(customers, games, movies, drama, rents);
	saveData(customers, games, movies, drama, rents);
	return 0;
}
