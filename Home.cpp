// Regina Elizabeth Flores Sosa A01770709
// Mariana Diaz Sanchez A01199454    
#include "Home.h"
#include <string>

using namespace std;

Home::Home()
{
	ID = 0;
    name=" ";
    length=0.0;
    genre=" ";
    rating = 0.0;
	rc = 0;
}

Home::Home(int id, string Name, double leng, string gen, double rate)
{
	ID = id;
	name = Name;
	length = leng;
	genre = gen;
	rating = rate;
}

void Home::setId(int id)
{
	ID = id;
}

void Home::setName(string Name)
{
	name = Name;
}

void Home::setLength(double leng)
{
	length = leng;
}

void Home::setGenre(string gen)
{
	genre = gen;
}

void Home::setRating(double rate)
{
	rating = rate;
}

int Home::getId()
{
	return ID;
}

string Home::getName()
{
	return name;
}

double Home::getLength()
{
	return length;
}

string Home::getGenre()
{
	return genre;
}

double Home::getRating()
{
	return rating;
}



