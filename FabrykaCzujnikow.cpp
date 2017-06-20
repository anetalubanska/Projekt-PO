#include "FabrykaCzujnikow.h"
#include <cstdlib>
#include <iostream>


FabrykaCzujnikow::FabrykaCzujnikow() {


}

Czujnik* FabrykaCzujnikow::stworz(const std::string &nazwa) {
    if(nazwa == "temperatury") {
        return new CzujnikTemperatury;
    } else if(nazwa == "wilgotnosci") {
        return new CzujnikWilgotnosci;
    } else {
        std::cout << "Wykryto blad, nie ma czujnika o nazwie: " << nazwa << std::endl;
        exit(1);
    }
}

FabrykaCzujnikow& FabrykaCzujnikow::pobierzFabryke() {
    static FabrykaCzujnikow obiekt;
    return obiekt;
}