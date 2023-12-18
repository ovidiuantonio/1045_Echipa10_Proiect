#pragma once
#include "Produs.h"
#include <iostream>

using namespace std;
class Client
{
protected:
	// vector de pointeri la obiecte de tip produs, relatie de has-a intre client si produse
	Produs** cos;
	int* cantitati = new int[5];
	int nrProduse;
	string nume;
	string telefon;
	int varsta;

public:
	Client();
	Client(string nume, string telefon, int varsta, int nrProduse, int cantitati, Produs** cos);
	~Client();

	void adaugaProdus(Produs produs, int cantitate);
	void scoateProdus(Produs produs);
	void afisareCos();
	void setDateClient();
	void afiseazaMeniu();

	string getNume();

	
};


