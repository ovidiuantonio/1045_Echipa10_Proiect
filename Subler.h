#pragma once
#include "Produs.h"
#include <iostream>

using namespace std;

class Subler : public Produs
{
protected:
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
    string getNume();

    void setDistantaMaxima(int distantaMaxima);
    int getDistantaMaxima();

    void afisareDetalii();
    void editareProdus();

    void serialize(ofstream& fout) const;
    void deserialize(ifstream& fin);
};

