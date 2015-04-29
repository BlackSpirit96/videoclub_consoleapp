#include <iostream>

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

void loadData(DynamicArray<Customer> &customers, DynamicArray<Game> &games, DynamicArray<Movie> &movies, DynamicArray<Drama> &drama, DynamicArray<Rent> &rents)
{
	// todo other:load data
}

bool getInput(string message)
{
	char choice;
	cout<<message;
	do
	{
		cin.get(choice);
		choice = tolower(choice);
	} while (choice != 'y' || choice != 'n');
	if (choice == 'y')
		return true;
	else
		return false;
}

void insertGame(DynamicArray<Game> &games)
{
	int id, year;
	string serial, title, genre, console;
	cout<<"Enter game id: ";
	cin>>id;
	cout<<"Enter game title: ";
	getline(cin, title);
	cout<<"Enter game serial: ";
	cin>>serial;
	cout<<"Enter game genre: ";
	cin>>genre;
	cout<<"Enter game console type: ";
	cin>>console;
	cout<<"Enter game production year: ";
	cin>>year;
	Game newGame(id, serial, title, genre, year, console);
	games.insert(newGame);
}

void insertMovie(DynamicArray<Movie> &movies)
{
	int id, year;
	string serial, title, genre, director, actors;
	char dvdc;
	struct time duration;
	cout<<"Enter movie id : ";
	cin>>id;
	cout<<"Enter movie serial : ";
	cin>>serial;
	cout<<"Enter movie title : ";
	getline(cin, title);
	cout<<"Enter movie genre : ";
	cin>>genre;
	cout<<"Enter movie year : ";
	cin>>year;
	cout<<"Enter movie director : ";
	getline(cin, director);
	cout<<"Enter movie actors : ";
	getline(cin, actors);
	cout<<"Is movie in dvd form ?<y/n>";
	cin>>dvdc;
	dvdc = tolower(dvdc);
	while ( dvdc != 'y' || dvdc != 'n')
	{
		cout<<"Is movie in dvd form ?<y/n>";
		cin>>dvdc;
		dvdc = tolower(dvdc);
	}
	cout<<"Enter movie duration (hour min sec) : ";
	cin>>duration.hours>>duration.minutes>>duration.seconds;
	movies.insert(Movie(id,serial, title, genre, year, director, actors, dvdc == 'y', duration));
	return;
}

void insertDrama(DynamicArray<Drama> &drama)
{
	int id, year, season;
	string serial, title, genre, director, actors;
	struct range episodes;
	char dvdc;
	cout<<"Enter drama id : ";
	cin>>id;
	cout<<"Enter drama serial : ";
	cin>>serial;
	cout<<"Enter drama title : ";
	getline(cin, title);
	cout<<"Enter drama genre : ";
	cin>>genre;
	cout<<"Enter drama year : ";
	cin>>year;
	cout<<"Enter drama director : ";
	getline(cin, director);
	cout<<"Enter drama actors : ";
	getline(cin, actors);
	cout<<"Is drama in dvd form ?<y/n>";
	cin>>dvdc;
	dvdc = tolower(dvdc);
	while ( dvdc != 'y' || dvdc != 'n')
	{
		cout<<"Is drama in dvd form ?<y/n>";
		cin>>dvdc;
		dvdc = tolower(dvdc);
	}
	cout<<"Enter drama season: ";
	cin>>season;
	cout<<"Enter drama episode rage(start stop): ";
	cin>>episodes.start>>episodes.end;
	drama.insert(Drama(id, serial, title, genre, year, director, actors, dvdc == 'y', season, episodes));
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
		cin>>choice;
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
			cout<<"Enter game id: ";
			cin>>id;
			games.printSearch(id);
			games.remove(id);
			cout<<"Enter new game data."<<endl;
			insertGame(games);
		}
		else if (choice == '4')
		{
			int id;
			cout<<"======< Game Remove >======"<<endl;
			cout<<"Enter game id: ";
			cin>>id;
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
				cout<<"Enter game title: ";
				cin>>term;
			}
			else
			{
				int term;
				cout<<"Enter game id: ";
				cin>>term;
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
		cin>>choice;
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
			cout<<"Enter movie id: ";
			cin>>id;
			movies.printSearch(id);
			movies.remove(id);
			cout<<"Enter new movie data."<<endl;
			insertMovie(movies);
		}
		else if (choice == '4')
		{
			int id;
			cout<<"======< Movie Remove >======"<<endl;
			cout<<"Enter movie id: ";
			cin>>id;
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
				cout<<"Enter movie title: ";
				cin>>term;
			}
			else
			{
				int term;
				cout<<"Enter movie id: ";
				cin>>term;
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
		cout<<" [3] Update dramae"<<endl;
		cout<<" [4] Remove drama"<<endl;
		cout<<" [5] Search available drama"<<endl;
		cout<<" [Q] Main Menu"<<endl;
		cin>>choice;
		choice = tolower(choice);
		if (choice == '1')
		{
			cout<<"======< Drama List >======"<<endl;
			drama.print();
		}
		else if (choice == '2')
		{
			cout<<"======< New movie >======"<<endl;
			insertDrama(drama);
		}
		else if (choice == '3')
		{
			int id;
			cout<<"======< Drama Update >======"<<endl;
			cout<<"Enter drama id: ";
			cin>>id;
			drama.printSearch(id);
			drama.remove(id);
			cout<<"Enter new drama data."<<endl;
			insertDrama(drama);
		}
		else if (choice == '4')
		{
			int id;
			cout<<"======< Drama Remove >======"<<endl;
			cout<<"Enter drama id: ";
			cin>>id;
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
				cout<<"Enter drama title: ";
				cin>>term;
			}
			else
			{
				int term;
				cout<<"Enter drama id: ";
				cin>>term;
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
		cin>>choice;
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

void insertCustomer(DynamicArray<Customer> &customers)
{
	string id, firstName, lastName, dateOfBirth, gender, address, phoneNumber;
	string creditCardNumber, issuingNetwork;
	int cvv;
	char vip;
	cout<<"Enter id number: ";
	cin>>id;
	cout<<"Enter fistname: ";
	cin>>firstName;
	cout<<"Enter lastname: ";
	cin>>lastName;
	cout<<"Enter date of birth: ";
	getline(cin, dateOfBirth);
	cout<<"Enter gender: ";
	cin>>gender;
	// todo 999 : gender = tolower(gender);
	cout<<"Enter address: ";
	getline(cin, address);
	cout<<"Enter phone number: ";
	cin>>phoneNumber;
	while(vip != 'y' || vip != 'n')
	{
		cout<<"Is the customer a VIP one ?<y/n>";
		cin>>vip;
		vip = tolower(vip);
	}
	if(vip == 'y')
	{
		cout<<"Enter cradit card number: ";
		cin>>creditCardNumber;
		cout<<"Enter credit card issuing network: ";
		cin>>issuingNetwork;
		cout<<"Enter cradit card cvv number: ";
		cin>>cvv;
		customers.insert(VIP(id, firstName, lastName, dateOfBirth, gender, address, phoneNumber, creditCardNumber, issuingNetwork, cvv));
	}
	else
	{
		customers.insert(Customer(id, firstName, lastName, dateOfBirth, gender, address, phoneNumber));
	}
}

void customerMenu(DynamicArray<Customer> &customers)
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
		cin>>choice;
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
			cout<<"Enter customer id: ";
			cin>>id;
			customers.printSearch(id);
			customers.remove(id);
			cout<<"Enter new customer data."<<endl;
			insertCustomer(customers);
		}
		else if (choice == '4')
		{
			string id;
			cout<<"======< Customer Remove >======"<<endl;
			cout<<"Enter customer id: ";
			cin>>id;
			customers.remove(id);
		}
		else if (choice == 'q')
			break;
	}
}

void rentMenu(DynamicArray<Customer> &customers, DynamicArray<Game> &games, DynamicArray<Movie> &movies, DynamicArray<Drama> &drama, DynamicArray<Rent> &rents)
{
	char choice;
	while(true)
	{
		cout<<"======< Rent Menu >======"<<endl;
		cout<<" [1] Rent a game"<<endl;
		cout<<" [2] Rent a movie"<<endl;
		cout<<" [3] Rent a drama"<<endl;
		cout<<" [4] Checkout rent"<<endl;
		cout<<" [Q] Main Menu"<<endl;
		cin>>choice;
		choice = tolower(choice);
		if (choice == '1')
		{
			string customerID, itemSerial;
			Date date;
			cout<<"Enter customer id: ";
			cin>>customerID;
			cout<<"Enter item serial number: ";
			cin>>itemSerial;
			cout<<"Enter day: ";
			cin>>date.day>>date.month>>date.year;
			rents.insert(Rent(customerID, itemSerial, date, customers.search(customerID)->isVIP(), false, "game"));
		}
		else if (choice == '2')
		{
			string customerID, itemSerial;
			Date date;
			cout<<"Enter customer id: ";
			cin>>customerID;
			cout<<"Enter item serial number: ";
			cin>>itemSerial;
			cout<<"Enter day: ";
			cin>>date.day>>date.month>>date.year;
			rents.insert(Rent(customerID, itemSerial, date, customers.search(customerID)->isVIP(), movies.search(itemSerial)->isDvd(), "movie"));
		}
		else if (choice == '3')
		{
			string customerID, itemSerial;
			Date date;
			cout<<"Enter customer id: ";
			cin>>customerID;
			cout<<"Enter item serial number: ";
			cin>>itemSerial;
			cout<<"Enter day: ";
			cin>>date.day>>date.month>>date.year;
			rents.insert(Rent(customerID, itemSerial, date, customers.search(customerID)->isVIP(), drama.search(itemSerial)->isDvd(), "drama"));
		}
		else if (choice == '4')
		{
			string itemSerial;
			cout<<"Enter item serial number: ";
			cin>>itemSerial;
			cout<<"Checkout: "<<rents.search(itemSerial)->checkout(TODAY_DAY)<<endl;
			rents.remove(itemSerial);
		}
		else if (choice == 'q')
		{
			break;
		}
	}
}

void mainMenu(DynamicArray<Customer> &customers, DynamicArray<Game> &games, DynamicArray<Movie> &movies, DynamicArray<Drama> &drama, DynamicArray<Rent> &rents)
{
	char choice;
	while(true)
	{
		cout<<"======< Main Menu >======"<<endl;
		cout<<" [1] Item management"<<endl;
		cout<<" [2] Customer management"<<endl;
		cout<<" [3] Rent management"<<endl;
		cout<<" [Q] Save & Quit"<<endl;
		cin>>choice;
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

void saveData(DynamicArray<Customer> &customers, DynamicArray<Game> &games, DynamicArray<Movie> &movies, DynamicArray<Drama> &drama, DynamicArray<Rent> &rents)
{
	// todo other:save data
}

int main() {
	cout<<"Enter today date: ";
	cin>>TODAY_DAY;
	DynamicArray<Customer> customers(100);
	DynamicArray<Game> games(100);
	DynamicArray<Movie> movies(100);
	DynamicArray<Drama> drama(100);
	DynamicArray<Rent> rents(100);
	loadData(customers, games, movies, drama, rents);
	mainMenu(customers, games, movies, drama, rents);
	saveData(customers, games, movies, drama, rents);
	return 0;
}
