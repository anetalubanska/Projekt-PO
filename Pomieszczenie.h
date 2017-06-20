#ifndef INTELIGENTNYDOM_POMIESZCZENIE_H
#define INTELIGENTNYDOM_POMIESZCZENIE_H

#include <vector>
#include <string>
#include "Czujnik.h"

class Pomieszczenie {
    std::string nazwa;
    std::vector<Czujnik*> czujniki;
public:
    void dodajCzujnik(Czujnik* czujnik);
    void wypisz() const;

    void ustawNazwe(const std::string& n);
    const std::string& zwrocNazwe() const;

    ~Pomieszczenie();

};


#endif
