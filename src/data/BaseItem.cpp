#include "BaseItem.h"

BaseItem::BaseItem(int id, string serial, string title, string genre, int year, bool availability)
{
	this->id = id;
	this->serial = serial;
	this->title = title;
	this->genre = genre;
	this->year = year;
	this->availability = availability;
}

BaseItem::BaseItem()
{
	this->id = 0;
	this->serial = "";
	this->title = "";
	this->genre = "";
	this->year = 0;
	this->availability = false;
}

string BaseItem::getGenre()
{
    return genre;
}

int BaseItem::getId()
{
    return id;
}

string BaseItem::getSerial()
{
    return serial;
}

string BaseItem::getTitle()
{
    return title;
}

int BaseItem::getYear()
{
    return year;
}

void BaseItem::setGenre(string genre)
{
    this->genre = genre;
}

void BaseItem::setId(int id)
{
    this->id = id;
}

void BaseItem::setSerial(string serial)
{
    this->serial = serial;
}

void BaseItem::setTitle(string title)
{
    this->title = title;
}

void BaseItem::setYear(int year)
{
    this->year = year;
}

bool BaseItem::operator==(int number)
{
	return id == number;
}

bool BaseItem::operator==(string text)
{
	return title == text;
}

bool BaseItem::operator==(BaseItem &item)
{
	return this->id == item.getId() && this->serial == item.getSerial();
}

bool BaseItem::isAvailable()
{
	return availability;
}

void BaseItem::setAvailability(bool available)
{
	this->availability = available;
}

ostream& BaseItem::print(ostream& mystream)
{
	return mystream<<id<<" "<<title<<" "<<serial<<" "<<genre<<" "<<year<<" "<<availability;
}

ostream &operator<<(ostream &mystream, BaseItem &item)
{
	return item.print(mystream);
}

istream& BaseItem::readData(istream &mystream)
{
	return mystream>>id>>title>>serial>>genre>>year>>availability;
}

istream &operator>>(istream &mystream, BaseItem &item)
{
	return item.readData(mystream);
}
