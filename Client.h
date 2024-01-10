#pragma once
#include "Produs.h"
#include "Magazin.h"
#include <iostream>
#include <vector> 

#include "IMagazin.h"

using namespace std;

class Client : public IMagazin
{
private:
	// vector de pointeri la obiecte de tip produs, relatie de has-a intre client si produse
	vector<int> cantitati;
	int nrProduseCos;
	Produs** produseCosClient;
	string nume;
	string telefon;
	int varsta;

public:
	Client();
	Client(string nume, string telefon, int varsta, int nrProduseCos, int* cantitati, Produs** produseCosClient);
	~Client();

	void afisareCos();

	//metode interfata
	void afiseazaMeniu();
	void afiseazaMeniuAdauga();
	void afiseazaMeniuSterge();
	void afiseazaMeniuEditare();
	void afiseazaMeniuProduseMagazin();

	string getNume();
	int getNrProduseCos();

	friend istream& operator>>(istream& cin, Client& client);
	friend ostream& operator<<(ostream& cout, const Client& client);
};


