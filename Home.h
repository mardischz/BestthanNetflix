// Regina Elizabeth Flores Sosa A01770709
// Mariana Diaz Sanchez A01199454    
#ifndef HOME_H
#define HOME_H
#include <iostream>
#include <string>
using namespace std;

class Home
{
protected:
	int ID;
	string name;
	double length;
	string genre;
	double rating;
	int rc = 0; //This is used in the Update Rating

public:
	Home();
	Home(int ID, string name, double length, string genre, double rating);

	void setId(int ID);
	void setName(string name);
	void setLength(double length);
	void setGenre(string genre);
	void setRating(double rating);

	int getId();
	string getName();
	double getLength();
	string getGenre();
	double getRating();	

	virtual void UpdateRating(double rating)=0;
	virtual void displayInfo()=0; 
};
#endif