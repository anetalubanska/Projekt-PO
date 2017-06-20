#include "Pomieszczenie.h"
#include "CzujnikTemperatury.h"
#include "FabrykaCzujnikow.h"
#include <iostream>

void Pomieszczenie::dodajCzujnik(Czujnik *czujnik) {
    czujniki.push_back(czujnik);
}

void Pomieszczenie::wypisz() const {
    std::cout << nazwa << std::endl;
    for(int i = 0; i < czujniki.size(); i++) {
        czujniki[i]->wylosujNapiecie();
        czujniki[i]->wypiszStan();
        std::cout << std::endl;
    }
}

void Pomieszczenie::ustawNazwe(const std::string &n) {
    nazwa = n;
}

Pomieszczenie::~Pomieszczenie() {
    for(int i = 0; i < czujniki.size(); i++) {
        delete czujniki[i];
    }
}

const std::string &Pomieszczenie::zwrocNazwe() const {
    return nazwa;

}
