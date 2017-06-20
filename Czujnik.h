#ifndef INTELIGENTNYDOM_CZUJNIK_H
#define INTELIGENTNYDOM_CZUJNIK_H


class Czujnik {
protected:
    double napiecie;
public:
    virtual void wypiszStan() const = 0;
    void wylosujNapiecie();
    double odczytajNapiecie() const;
    virtual ~Czujnik();
};


#endif
