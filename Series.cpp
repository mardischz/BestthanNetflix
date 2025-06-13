// Regina Elizabeth Flores Sosa A01770709
// Mariana Diaz Sanchez A01199454 
#include "Series.h"
#include "Home.h"

Series::Series() {}

Series::Series(int id, string Name, double leng, string gen, double rate)
    : Home(id, Name, leng, gen, rate) {}

void Series::UpdateRating(double rate)
{
    rc += 1;
    rating = (rating * (rc - 1) + rate) / rc;
}

void Series::displayInfo()
{
    cout << "-------- SERIES INFO --------" << endl;
    cout << "ID: " << ID << endl;
    cout << "Name: " << name << endl;
    cout << "Length: " << length << " minutes" << endl;
    cout << "Genre: " << genre << endl;
    cout << "Rating: " << rating << " /5" << endl;
}

void Series::loadFromFile() {}
