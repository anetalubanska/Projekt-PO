#include <iostream>
#include "CzujnikTemperatury.h"


void CzujnikTemperatury::wypiszStan() const {
    std::cout << "CZUJNIK TEMPERATURY\n";
    std::cout << "Temperatura = " << odczytajNapiecie() / 2 * 10 + 5 << std::endl;
}