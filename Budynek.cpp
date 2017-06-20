#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Budynek.h"
#include "FabrykaCzujnikow.h"

void Budynek::dodajPomieszczenie(Pomieszczenie* pomieszczenie) {
    pomieszczenia.push_back(pomieszczenie);
}

void Budynek::wypiszStanPomieszczen() const {
    std::cout << "WYPISUJE STAN POMIESZCZEN\n";
    for(int i = 0; i < pomieszczenia.size(); i++) {
        pomieszczenia[i]->wypisz();
    }
}

void Budynek::wypiszStanPomieszczenia() {

    if(pomieszczenia.size() == 0) {
        std::cout << "Brak pomieszczen.\n";
        return;
    }

    std::cout << "Dostepne pomieszczenia: \n";
    for(int i = 0; i < pomieszczenia.size(); i++) {
        std::cout << i+1 << ") " << pomieszczenia[i]->zwrocNazwe() << std::endl;
    }

    int numer = 0;

    do {
        std::cout << "Podaj numer pomieszczenia: ";
        std::cin >> numer;

    } while(numer > pomieszczenia.size() || numer <= 0);

    pomieszczenia[numer-1]->wypisz();

}

bool Budynek::czyJestTakiePomieszczenie(const std::string &nazwa) {
    for(int i = 0; i < pomieszczenia.size(); i++) {
        if(nazwa == pomieszczenia[i]->zwrocNazwe()) {
            return true;
        }
    }

    return false;
}
void Budynek::kreatorPomieszczenia() {
    std::string nazwa;
    do {
        std::cout << "Podaj nazwe pomieszczenia: ";
        std::cin >> nazwa;
    } while(czyJestTakiePomieszczenie(nazwa));

    Pomieszczenie* pomieszczenie = new Pomieszczenie;
    pomieszczenie->ustawNazwe(nazwa);
    pomieszczenia.push_back(pomieszczenie);
}


void Budynek::kreatorCzujnika() {
    std::string typ;

    if(pomieszczenia.size() == 0) {
        std::cout << "Nie ma pomieszczenia do ktorego moge dodac czujnik.\n";
        return;
    }
    do {
        std::cout << "Podaj typ czujnika [temperatury/wilgotnosci]: ";
        std::cin >> typ;
    } while(typ != "temperatury" && typ != "wilgotnosci");

    std::cout << "Dostepne pomieszczenia: \n";
    for(int i = 0; i < pomieszczenia.size(); i++) {
        std::cout << i+1 << ") " << pomieszczenia[i]->zwrocNazwe() << std::endl;
    }

    int numer = 0;

    do {
        std::cout << "Podaj numer pomieszczenia w ktorym ma znalezc sie czujnik: ";
        std::cin >> numer;

    } while(numer > pomieszczenia.size() || numer <= 0);

    pomieszczenia[numer - 1]->dodajCzujnik(FabrykaCzujnikow::pobierzFabryke().stworz(typ));
}
void Budynek::menu() {
    int opcja = 0;
    do {
        std::cout << "1) Dodaj pomieszczenie.\n";
        std::cout << "2) Dodaj czujnik.\n";
        std::cout << "3) Wypisz stan czujnikow.\n";
        std::cout << "4) Wypisz stan czujnikow z pomieszczenia.\n";
        std::cout << "5) Wyjdz.\n";

        std::cin >> opcja;

        switch(opcja) {
            case 1:
                kreatorPomieszczenia();
                break;
            case 2:
                kreatorCzujnika();
                break;
            case 3:
                wypiszStanPomieszczen();
                break;
            case 4:
                wypiszStanPomieszczenia();
                break;
            case 5:
            std::cout << "Wychodze z programu.\n";
                break;
            default:
            std::cout << "Nie ma takiej opcji.\n";
        }

    } while(opcja != 5);
}

void Budynek::start() {
    menu();
}

Budynek::Budynek() {
    srand(time(0));
}


Budynek::~Budynek() {
    for(int i = 0; i < pomieszczenia.size(); i++) {
        delete pomieszczenia[i];
    }
}
