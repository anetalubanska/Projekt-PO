#ifndef INTELIGENTNYDOM_FABRYKACZUJNIKOW_H
#define INTELIGENTNYDOM_FABRYKACZUJNIKOW_H

#include <string>
#include "CzujnikTemperatury.h"
#include "CzujnikWilgotnosci.h"

class FabrykaCzujnikow {

    FabrykaCzujnikow();
    FabrykaCzujnikow(const FabrykaCzujnikow&);
public:
    static FabrykaCzujnikow& pobierzFabryke();
    Czujnik* stworz(const std::string& nazwa);
};


#endif //INTELIGENTNYDOM_FABRYKACZUJNIKOW_H
