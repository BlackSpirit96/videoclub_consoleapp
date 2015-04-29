/*
 * BaseItem.cpp
 *
 *  Created on: Apr 27, 2015
 *      Author: BlackSpirit
 */

#include "BaseItem.h"

BaseItem::BaseItem(int id, string serial, string title, string genre, int year)
{
	this->id = id;
	this->serial = serial;
	this->title = title;
	this->genre = genre;
	this->year = year;
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

