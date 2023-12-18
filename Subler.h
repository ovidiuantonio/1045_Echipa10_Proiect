#pragma once
#include "Produs.h"
#include <iostream>

using namespace std;

class Subler :
    public Produs
{
    string tip;
    string culoare;
    int distantaMaxima;

public:
    Subler();
    Subler(int cantitate, float pret, float rating, string nume, string marca, string desciere, string tip, string culoare, int distantaMaxima);

    void setTip(string tip);
    string getTip();

    void setCuloare(string culoare);
    string getCuloare();

    void setDistantaMaxima(int distantaMaxima);
    int getDistantaMaxima();

    void afisareDetalii();
};

