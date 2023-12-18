#pragma once
#include "Produs.h"
#include <iostream>

using namespace std;
class Magazin
{
protected:
	int* nrProduse;
	Produs** produse;
	string nume;

public:
	Magazin();
	Magazin(string nume, int nrproduse, Produs** produse);

	Produs* getProdus(int indexProdus);
	string getNume();
};

