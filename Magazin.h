#pragma once
#include "Produs.h"
#include "Subler.h"
#include "Bormasina.h"
#include "MasinaDeTunsIarba.h"
#include <iostream>
#include <fstream>

using namespace std;
class Magazin
{
protected:
	string nume;
	int nrProduseMagazin;
	Produs** produseMagazin;

public:
	Magazin();
	Magazin(string nume, int nrProduseMagazin, Produs** produseMagazin);
	~Magazin();

	string getNume();
	int getNrProduse();

	Produs* getProdus(int index);

	void setNume(string nume);

	void writeFileProduseMagazin();
	void readFileProduseMagazin();
	void adaugaProdusMagazin(Produs* produs);

	void afiseazaMeniu();
	void afiseazaMeniuAdauga();
	void vizualizareProduse();
	void editareProdusMagazin(Produs* produs);
	void stergereProdusMagazin(Produs* produs);

	Magazin operator-=(Produs* p);
	Produs& operator[](int index);
};

