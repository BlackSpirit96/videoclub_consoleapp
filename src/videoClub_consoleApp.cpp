#include <iostream>

//dataClasses
#include "data/Rent.h"

#include "data/Customer.h"
#include "data/Customers/VIP.h"

#include "data/Items/Game.h"
#include "data/Items/Media/Movie.h"
#include "data/Items/Media/Drama.h"
//listClasses

// todo list:customerList
// todo list:itemList
// todo list:rentList

using namespace std;


void loadData(CustomerList &customers, ItemList &games, ItemList &movies, ItemList &drama, RentList &rents)
{
	// todo other:load data
}

void insertGame(ItemList &games)
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
	games.add(Game(id, serial, title, genre, year, console));
}

void insertMovie(ItemList &movies)
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
	cin>>duration.hour>>duration.min>>duration.sec;
	movies.add(Movie(id,serial, title, genre, year, director, actors, dvdc == 'y', duration));
}

void insertDrama(ItemList &drama)
{
	int id, year, season;
	string serial, title, genre, irector, actors;
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
	drama.add(Drama(id, serial, title, genre, year, director, actors, dvd, searson, episodes));
}

void gamesMenu(ItemList &games)
{
	char choice;
	while (true)
	{
		cout<<"======< Games Menu >======"<<endl;
		cout<<" [1] Show games"<<endl;
		cout<<" [2] Add games"<<endl;
		cout<<" [3] Update game"<<endl;
		cout<<" [4] Remove game"<<endl;
		cout<<" [Q] Main Menu"<<endl;
		cin>>choice;
		choice = tolower(choice);
		if (choice == '1')
		{
			cout<<"======< Games List >======"<<endl;
			games.show();
		}
		else if (choice == '2')
		{
			cout<<"======< New Game >======"<<endl;
			insertGame(ItemList &games);
		}
		else if (choice == '3')
		{
			string id;
			cout<<"======< Game Update >======"<<endl;
			cout<<"Enter game id: ";
			cin>>id;
			games.printSearch(id);
			games.remove(id);
			cout<<"Enter new game data."<<endl;
			insertGame(ItemList &games);
		}
		else if (choice == '4')
		{
			string id;
			cout<<"======< Game Remove >======"<<endl;
			cout<<"Enter game id: ";
			cin>>id;
			games.remove(id);
		}
		else if (choice == 'q')
			break;
	}
}

void moviesMenu(ItemList &movies)
{
	char choice;
	while (true)
	{
		cout<<"======< Movies Menu >======"<<endl;
		cout<<" [1] Show movies"<<endl;
		cout<<" [2] Add movies"<<endl;
		cout<<" [3] Update movie"<<endl;
		cout<<" [4] Remove movie"<<endl;
		cout<<" [Q] Main Menu"<<endl;
		cin>>choice;
		choice = tolower(choice);
		if (choice == '1')
		{
			cout<<"======< Movies List >======"<<endl;
			movies.show();
		}
		else if (choice == '2')
		{
			cout<<"======< New movie >======"<<endl;
			insertMovie(ItemList &movies);
		}
		else if (choice == '3')
		{
			string id;
			cout<<"======< Movie Update >======"<<endl;
			cout<<"Enter movie id: ";
			cin>>id;
			movies.printSearch(id);
			movies.remove(id);
			cout<<"Enter new movie data."<<endl;
			insertMovie(ItemList &movies);
		}
		else if (choice == '4')
		{
			string id;
			cout<<"======< Movie Remove >======"<<endl;
			cout<<"Enter movie id: ";
			cin>>id;
			movies.remove(id);
		}
		else if (choice == 'q')
			break;
	}
}

void dramaMenu(ItemList &drama)
{
	char choice;
	while (true)
	{
		cout<<"======< Drama Menu >======"<<endl;
		cout<<" [1] Show drama"<<endl;
		cout<<" [2] Add drama"<<endl;
		cout<<" [3] Update dramae"<<endl;
		cout<<" [4] Remove drama"<<endl;
		cout<<" [Q] Main Menu"<<endl;
		cin>>choice;
		choice = tolower(choice);
		if (choice == '1')
		{
			cout<<"======< Drama List >======"<<endl;
			drama.show();
		}
		else if (choice == '2')
		{
			cout<<"======< New movie >======"<<endl;
			insertDrama(ItemList &drama);
		}
		else if (choice == '3')
		{
			string id;
			cout<<"======< Drama Update >======"<<endl;
			cout<<"Enter drama id: ";
			cin>>id;
			drama.printSearch(id);
			drama.remove(id);
			cout<<"Enter new drama data."<<endl;
			insertMovie(ItemList &drama);
		}
		else if (choice == '4')
		{
			string id;
			cout<<"======< Drama Remove >======"<<endl;
			cout<<"Enter drama id: ";
			cin>>id;
			drama.remove(id);
		}
		else if (choice == 'q')
			break;
	}
}

void itemMenu(ItemList &games, ItemList &movies, ItemList &drama)
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

void insertCustomer(CustomerList &customers)
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
		customers.add(VIP(id, fistName, lastName, dateOfBirth, gender, address, phoneNumber, creditCardNumber, issuingNetwork, cvv));
	}
	else
	{
		customers.add(Customer(id, fistName, lastName, dateOfBirth, gender, address, phoneNumber));
	}
}

void customerMenu(CustomerList &customers)
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
			customers.show();
		}
		else if (choice == '2')
		{
			cout<<"======< New Customer >======"<<endl;
			insertCustomer(CustomerList &customers);
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
			insertCustomer(CustomerList &customers);
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

void rentMenu(CustomerList &customers, RentList &rents)
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
			rents.add(Rent(customerID, itemSerial, date, customers.search(customerID).isVIP(), "game"));
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
			rents.add(Rent(customerID, itemSerial, date, customers.search(customerID).isVIP(), "movie"));
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
			rents.add(Rent(customerID, itemSerial, date, customers.search(customerID).isVIP(), "drama"));
		}
		else if (choice == '4')
		{
			string itemSerial;
			cout<<"Enter item serial number: ";
			cin>>itemSerial;
			cout<<"Checkout: "<<rents.search(itemSerial).checkout()<<endl; // todo I might place it in list
		}
		else if (choice == 'q')
		{
			break;
		}
	}
}

void mainMenu(CustomerList &customers, ItemList &games, ItemList &movies, ItemList &drama, RentList &rents)
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
			rentMenu(customers, rents);
		else if (choice == 'q')
			break;
	}
}

void saveData(CustomerList &customers, ItemList &games, ItemList &movies, ItemList &drama, RentList &rents)
{
	// todo other:save data
}

int main() {
	CustomerList customers();
	ItemList games();
	ItemList movies();
	ItemList drama();
	RentList rents();
	loadData(customers, games, movies, drama, rents);
	mainMenu(customers, games, movies, drama, rents);
	saveData(customers, games, movies, drama, rents);
	return 0;
}
