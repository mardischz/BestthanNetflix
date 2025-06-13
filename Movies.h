// Regina Elizabeth Flores Sosa A01770709
// Mariana Diaz Sanchez A01199454    
#ifndef MOVIES_H
#define MOVIES_H
#include <iostream>
#include <vector>
#include "Home.h"

using namespace std;

class Movies :public Home
{
public:
    Movies();
    Movies(int, string, double, string, double);

    void UpdateRating(double rating);
    void loadFromFile(string, vector<Home*>);
    void displayInfo();

};
#endif