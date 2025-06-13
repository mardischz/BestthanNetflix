#include "Episodes.h"
#include <iostream>
#include <string>
using namespace std;

// Constructor por defecto
Episodes::Episodes() {
    idep = 0;
    idSerie = 0;
    season = 0;
    nepisode = "";
    ratingep = 0.0;
    Re = 0;
}

// Constructor con parámetros
Episodes::Episodes(int IDe, int idS, int sea, string na_ep, double rat_ep) {
    idep = IDe;
    idSerie = idS;
    season = sea;
    nepisode = na_ep;
    ratingep = rat_ep;
    Re = 1; // Primera calificación
}

// Setters
void Episodes::setIdep(int IDe) {
    idep = IDe;
}

void Episodes::setIdSerie(int id) {
    idSerie = id;
}

void Episodes::setSeason(int sea) {
    season = sea;
}

void Episodes::setNEpisode(string na_ep) {
    nepisode = na_ep;
}

void Episodes::setRatingEp(double rat_ep) {
    ratingep = rat_ep;
    Re = 1; // Reemplaza el rating anterior, contador se reinicia
}

// Getters
int Episodes::getIdep() {
    return idep;
}

int Episodes::getIdSerie() {
    return idSerie;
}

int Episodes::getSeason() {
    return season;
}

string Episodes::getNEpisode() {
    return nepisode;
}

double Episodes::getRatingEp() {
    return ratingep;
}

// Acumula rating como promedio ponderado
void Episodes::UpdateRating(double rat_ep) {
    Re += 1;
    ratingep = (ratingep * (Re - 1) + rat_ep) / Re;
}

// Mostrar info del episodio
void Episodes::displayInfoEp() {
    cout << "-------- EPISODE INFO --------\n";
    cout << "Episode ID: " << idep << '\n';
    cout << "Series ID: " << idSerie << '\n';
    cout << "Season Number: " << season << '\n';
    cout << "Name: " << nepisode << '\n';
    cout << "Rating: " << ratingep << " / 5 stars\n";
}
