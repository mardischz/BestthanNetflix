// Regina Elizabeth Flores Sosa A01770709
//Mariana Diaz Sanchez A01199454
#ifndef EPISODES_H
#define EPISODES_H

#include <iostream>
#include <string>
using namespace std;

class Episodes {
private:
    int idep;           // ID del episodio
    int idSerie;        // ID de la serie a la que pertenece
    int season;         // Número de temporada
    string nepisode;    // Nombre del episodio
    double ratingep;    // Rating promedio del episodio
    int Re = 0;         // Contador para calcular el promedio de rating

public:
    // Constructores
    Episodes();
    Episodes(int idep, int idSerie, int season, string nepisode, double ratingep);

    // Setters
    void setIdep(int idep);
    void setIdSerie(int id);
    void setSeason(int season);
    void setNEpisode(string nepisode);
    void setRatingEp(double ratingep);

    // Getters
    int getIdep();
    int getIdSerie();
    int getSeason();
    string getNEpisode();
    double getRatingEp();

    // Función para actualizar el rating con promedio
    void UpdateRating(double newRating);

    // Mostrar información
    void displayInfoEp();
};

#endif

