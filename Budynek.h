#ifndef INTELIGENTNYDOM_BUDYNEK_H
#define INTELIGENTNYDOM_BUDYNEK_H


#include <vector>
#include "Pomieszczenie.h"

class Budynek {
    std::vector<Pomieszczenie*> pomieszczenia;

    void dodajPomieszczenie(Pomieszczenie* pomieszczenie);
    void wypiszStanPomieszczen() const;

    void kreatorPomieszczenia();
    void kreatorCzujnika();
    void wypiszStanPomieszczenia();

    void menu();

    bool czyJestTakiePomieszczenie(const std::string& nazwa);
public:
    Budynek();
    void start();

    ~Budynek();
};


#endif //INTELIGENTNYDOM_BUDYNEK_H
