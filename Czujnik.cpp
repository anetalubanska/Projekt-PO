#include "Czujnik.h"

#include <cstdlib>

void Czujnik::wylosujNapiecie() {
    napiecie = (double)(rand() % 501) / (double)100;
}

double Czujnik::odczytajNapiecie() const {
    return napiecie;
}

Czujnik::~Czujnik() {

}
