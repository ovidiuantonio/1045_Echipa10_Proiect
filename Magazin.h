#pragma once
#include "Produs.h"
#include "Subler.h"
#include "Bormasina.h"
#include "MasinaDeTunsIarba.h"
#include "Laptop.h"
#include "CombinaFrigorifica.h"
#include <iostream>
#include <fstream>

#include "IMagazin.h"

using namespace std;
class Magazin : public IMagazin
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

	void setNume(string nume);

	void writeFileProduseMagazin();
	void readFileProduseMagazin();
	void adaugaProdusMagazin(Produs* produs);

	//metode interfata
	void afiseazaMeniu();
	void afiseazaMeniuAdauga();
	void afiseazaMeniuEditare();
	void afiseazaMeniuSterge();
	void afiseazaMeniuProduseMagazin();

	void vizualizareProduse();
	void editareProdusMagazin(Produs* produs);
	void stergereProdusMagazin(int i);

	void operator-=(int i);
	Produs* operator[](int index);
	void operator+=(Produs* p);
};

