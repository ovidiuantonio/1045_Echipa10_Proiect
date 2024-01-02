#pragma once
#include "Produs.h"
#include <iostream>

using namespace std;
class Magazin: public Produs
{
private:
	string nume;
	int nrProduseMagazin;
	Produs** produseMagazin;

public:
	Magazin();
	Magazin(string nume, int nrProduseMagazin, Produs** produseMagazin);
	~Magazin();

	string getNume();
	Produs** getProduseMagazin();

	void setNume(string nume);

	void adaugaProdusMagazin(Produs* produs);

	void afiseazaMeniu();
	void vizualizareProduse();
};

