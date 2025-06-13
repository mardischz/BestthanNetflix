// Regina Elizabeth Flores Sosa A01770709
// Mariana Diaz Sanchez A01199454    
#ifndef SERIES_H
#define SERIES_H
#include <iostream>
#include "Home.h"

using namespace std;

class Series :public Home
{
public:
	Series();
	Series(int, string, double, string, double);

	void UpdateRating(double rating);
	void displayInfo();
	void loadFromFile();
	//operator 
	
};
#endif