//Regina Elizabeth Flores Sosa A01770709
//Mariana Diaz Sanchez A01199454 

#include "Home.cpp"
#include "Movies.cpp"
#include "Series.cpp"
#include "Episodes.cpp"
#include "json.h"
#include <iostream>
#include <vector>
#include <fstream>


using json = nlohmann::json;
using namespace std;

void ShowMenu() {
    cout << "\033[1;34m------------- MENU ------------\033[0m" << endl;
    cout << "\033[1;31;47m1. Load Data File\033[0m " << endl;
    cout << "\033[7;30;106ma) Show Movies by rating\033[0m" << endl;
    cout << "b) Show Series by rating" << endl;
    cout << "c) Show Episodes by rating" << endl;
    cout << "d) Exit" << endl;
    cout << "-------------------------------" << endl;
}

int main() {

    json catalog;
    vector<Movies> movieList;
    vector<Series> seriesList;
    vector<Episodes> episodeList;
    bool dataLoaded = false;

    char op;
    while (true) {
        ShowMenu();
        cout << "Enter your option: ";
        cin >> op;

        switch (op) {
        case '1': {
            ifstream file("Catalogo.json");
            if (!file.is_open()) {
                cerr << "Error opening file.\n";
                break;
            }

            catalog.clear();
            file >> catalog;
            movieList.clear();
            seriesList.clear();
            episodeList.clear();
//peliculas 
            for (auto& m : catalog["Movies"]) {
                Movies mov(
                    m["ID"],
                    m["name"],
                    m["length"],
                    m["genre"],
                    m["rating"]
                );
                movieList.push_back(mov);
            }
//series y episodios
            for (auto& s : catalog["Series"]) {
                Series serie(
                    s["ID"],
                    s["name"],
                    s["length"],
                    s["genre"],
                    s["rating"]
                );
                seriesList.push_back(serie);

                for (auto& season : s["seasons"]) {
                    int seasonNumber = season["season"];
                    //aqui cambio a nuevo
                    for (auto& ep : season["episodes"]) {
                        int idepValue=0;//lo incializamos en cero 
                        if (ep["idep"].is_number_integer()){
                            idepValue=ep["idep"].get<int>();//forzandola a ser int 
                        } else {
                            cout << "Error idep has changed Value:"<< ep["idep"] <<endl;//enseñar el valor q tiene
                            continue;
                        }

                        Episodes e(
                            idepValue,
                            s["ID"],
                            seasonNumber,
                            ep["name"],
                            ep["ratingep"]
                        );
                        episodeList.push_back(e);
                    }
                }
            }

            cout << "------------Data loaded successfully------------\n";
            dataLoaded = true;
            break;
        }

        case 'a': {
            if (!dataLoaded) {
                cout << "***********Please load the data file first**********\n";
                break;
            }

            cout << "\n--------Available Movie--------\n";
            for (auto& m : movieList) {
                m.displayInfo();
            }

            int idToRate;
            cout << "\nEnter the ID of the movie: ";
            cin >> idToRate;

            bool found = false;
            for (auto& m : movieList) {
                if (m.getId() == idToRate) {
                    found = true;
                    m.displayInfo();

                    string choice; 
                    cout << "\nDo you want to rate this movie? (yes/no): ";
                    cin >> choice;

                    if (choice == "yes" || choice == "Yes") {
                        double newRating;
                        cout << "\nEnter rating (1 - 5): ";
                        cin >> newRating;
                        if (newRating > 5.0) newRating = 5.0;
                        m.UpdateRating(newRating);
                        cout << "Thanks for rating the movie, hope you enjoyed!\n";
                    }
                    break;
                }
            }
            if (!found) {
                cout << "Movie ID not found, try again\n";
            }
            break;
        }

        case 'b': {
            if (!dataLoaded) {
                cout << "***********Please load the data file first**********\n";
                break;
            }

            cout << "\n--------Available Series--------\n";
            for (auto& s : seriesList) {
                s.displayInfo();
            }

            int IDserieRate;
            cout << "\nEnter the ID of the Series: ";
            cin >> IDserieRate;

            bool foundSerie = false;
            for (auto& s : seriesList) {
                if (s.getId() == IDserieRate) {
                    foundSerie = true;

                    vector<Episodes*> selectedEpisodes;
                    int count = 1;
/////////////////////////////////////////////////checar si no rompe
                    cout << "Episodes in \n" << s.getName() << "\":\n";
                    //aqui escribo yo 
                    for (int temp=1; temp<=10; ++temp){
                        bool hayEpisodios=false;

                        for (auto& e : episodeList) {
                            if (e.getIdSerie() == IDserieRate && e.getSeason() ==temp) 
                            {
                                if (!hayEpisodios) {
                                    cout <<"\nSeason"<<temp<<":\n";
                                    hayEpisodios=true;
                                }

                                cout << count << ". " << e.getNEpisode()
                                     << " - Rating: " << e.getRatingEp() << "/5\n";
                                selectedEpisodes.push_back(&e);
                                count++;

                            }

                        }   
                    }


                    int epNum;
                    cout << "\nEnter episode number: ";
                    cin >> epNum;

                    if (epNum >= 1 && epNum <= selectedEpisodes.size()) {
                        Episodes* selectedEp = selectedEpisodes[epNum - 1];
                        selectedEp-> displayInfoEp();

                        string rateEp; 
                        cout << "\nDo you want to rate this episode? (yes/no):";
                        cin >> rateEp;
                        if (rateEp == "yes" || rateEp == "Yes") {
                            double newEpRating;
                            cout << "Enter rating (1 - 5): ";
                            cin >> newEpRating;
                            if (newEpRating > 5.0) newEpRating = 5.0;
                            selectedEp->UpdateRating(newEpRating);
                            cout << "Thanks for rating the episode, hope you enjoyed!\n";
                        }

                        string rateSerie; 
                        cout << "\nDo you also want to rate the full series? (yes/no): ";
                        cin >> rateSerie;
                        if (rateSerie == "yes" || rateSerie == "Yes") {
                            double newSerieRating;
                            cout << "Enter rating (1 - 5): ";
                            cin >> newSerieRating;
                            if (newSerieRating > 5.0) newSerieRating = 5.0;
                            s.UpdateRating(newSerieRating);
                            cout << "Thanks for rating the series, hope you enjoyed!\n";
                        }
                    } else {
                        cout << "Episode number not found\n";
                    }
                    break;
                }
            }

            if (!foundSerie) {
                cout << "Series ID not found.\n";
            }

            break;
        }

        case 'c': {
            if (!dataLoaded) {
                cout <<"**************Please load the data file first++++++++++++\n";
                break;
            }

            double filtro;
            cout <<"\nEnter minimum episode rating(1-5):";
            cin>>filtro;

            cout <<"\n ------Episodes with rating >="<< filtro <<"-------\n";

            bool found =false;
            for(auto& e:episodeList) {
                if (e.getRatingEp() >=filtro) {
                    e.displayInfoEp();
                    found=true;
                }
            }

            if (!found) {
                cout << "No episodes found with rating >=" << filtro << endl;
            }

            break;
        }

        case 'd': {
            catalog["Movies"].clear();
            for (auto& m : movieList) {
                catalog["Movies"].push_back({
                    {"ID", m.getId()},
                    {"name", m.getName()},
                    {"length", m.getLength()},
                    {"genre", m.getGenre()},
                    {"rating", m.getRating()}
                });
            }

            catalog["Series"].clear();
            for (auto& s : seriesList) {
                json serieJson = {
                    {"ID", s.getId()},
                    {"name", s.getName()},
                    {"length", s.getLength()},
                    {"genre", s.getGenre()},
                    {"rating", s.getRating()},
                    {"seasons", json::array()}
                };

                for (int temp = 1; temp <= 10; ++temp) {
                    json temporadaJson;
                    temporadaJson["season"] = temp;
                    temporadaJson["episodes"] = json::array();

                    bool hayEpisodios = false;
                    for (auto& ep : episodeList) {
                        if (ep.getIdSerie() == s.getId() && ep.getSeason() == temp) {
                            temporadaJson["episodes"].push_back({
                                {"idep", ep.getIdep()},
                                {"name", ep.getNEpisode()},
                                {"ratingep", ep.getRatingEp()}
                            });
                            hayEpisodios = true;
                        }
                    }
                    if (hayEpisodios) {
                        serieJson["seasons"].push_back(temporadaJson);
                    }
                }

                catalog["Series"].push_back(serieJson);
            }

            ofstream outFile("Catalogo.json");
            outFile << catalog.dump(2);
            outFile.close();

            cout << "Thanks for using the program.\n";
            return 0;
        }
        }
    }
}
