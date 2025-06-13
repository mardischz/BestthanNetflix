// Regina Elizabeth Flores Sosa A01770709

// Mariana Diaz Sanchez A01199454   
#include "Movies.h" 
#include "Home.h"

Movies::Movies() {}

Movies::Movies(int id, string Name, double leng, string gen, double rate): Home(id, Name, leng, gen, rate)
{

}

void Movies::UpdateRating(double rate)
{
	rc += 1;
	rating = (rating * (rc - 1) + rate) / rc;
}

void Movies::displayInfo()
{
	cout << "-------- MOVIE INFO --------" << endl;
	cout << "ID:" << ID << endl;
	cout << "Name: " << name << endl;
	cout << "Length: " << length << " minutes" << endl;
	cout << "Genre: " << genre << endl;
	cout << "Rating: " << rating << " /5" << endl;
}


void Movies::loadFromFile(string, vector <Home*>)
{

}