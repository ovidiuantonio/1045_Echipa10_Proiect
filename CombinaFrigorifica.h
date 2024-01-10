#pragma once
#include "Produs.h"
#include <iostream>

using namespace std;

class CombinaFrigorifica : public Produs
{
private:
    int capacitateCongelare;
    int greutate;
    string culoare;

public:
    CombinaFrigorifica();
    CombinaFrigorifica(int cantitate, float pret, float rating, string nume, string marca, string descriere, int capacitateCongelare, int greutate, string culoare);

    void setCapacitateCongelare(int capacitateCongelare);
    int getCapacitateCongelare();

    void setGreutate(int greutate);
    int getGreutate();

    void setCuloare(string culoare);
    string getCuloare();

    void afisareDetalii();
    void editareProdus();

    void serialize(ofstream& fout) const;
    void deserialize(ifstream& fin);
};