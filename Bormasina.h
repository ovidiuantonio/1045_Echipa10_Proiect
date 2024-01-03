#pragma once
#include "Produs.h"
#include <iostream>

using namespace std;

class Bormasina : public Produs
{
private:
    string tipAlimentare;
    int putere;
    int areBateriaInclusa;

public:
    Bormasina();
    Bormasina(int cantitate, float pret, float rating, string nume, string marca, string descriere, string tipAlimentare, int putere, int areBateriaInclusa);

    string getNume();
    void setTipAlimentare(string tipAlimentare);
    string getTipAlimentare();

    void setPutere(int putere);
    int getPutere();

    void setAreBateriaInclusa(bool areBateriaInclusa);
    int getAreBateriaInclusa();

    void afisareDetalii();
    void editareProdus();

    void serialize(ofstream& fout) const;
    void deserialize(ifstream& fin);
};