#pragma once
#include "Produs.h"
#include <iostream>

using namespace std;
class Magazin
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
	void editareProdusMagazin(Produs* produs);
	void stergereProdusMagazin(Produs* produs);

	Magazin operator-=(Produs* p);
};

