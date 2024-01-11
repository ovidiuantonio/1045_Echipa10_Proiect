#pragma once
#include "Produs.h"
#include <iostream>

using namespace std;

class MasinaDeTunsIarba : public Produs
{
    string serie;
    string culoare;
    float marimeRezervor;

public:
    MasinaDeTunsIarba();
    MasinaDeTunsIarba(int idProdus, int cantitate, float pret, float rating, string nume, string marca, string desciere, string serie, string culoare, float marimeRezervor);

    void setSerie(string serie);
    string getSerie();

    void setCuloare(string culoare);
    string getCuloare();
    string getNume();

    void setMarimeRezervor(int marimeRezervor);
    int getMarimeRezervor();

    void afisareDetalii();
    void editareProdus();
    friend ofstream& operator<<(ofstream& out, MasinaDeTunsIarba& m);

    virtual void serialize(ofstream& fout) const;
    virtual void deserialize(ifstream& fin);
};

