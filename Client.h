#pragma once
#include "Produs.h"
#include <iostream>

using namespace std;

class Client
{
private:
	// vector de pointeri la obiecte de tip produs, relatie de has-a intre client si produse
	int* cantitati;
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
	void afiseazaMeniu();

	string getNume();

	friend istream& operator>>(istream& cin, Client& client);
	friend ostream& operator<<(ostream& cout, const Client& client);
};


