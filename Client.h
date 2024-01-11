#pragma once
#include "Produs.h"
#include "Subler.h"
#include "Bormasina.h"
#include "MasinaDeTunsIarba.h"
#include "Laptop.h"
#include "CombinaFrigorifica.h"
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
	void adaugaProdusInCos(Produs* produs, int cantitate);
	void scoateProdusDinCos(int nrProdus);
	void afiseazaMeniuUltimaComanda();

	string getNume();
	string getTelefon();
	int getNrProduseCos();
	Produs** getProduseCosClient();
	vector<int> getCantitati();

	void salveazaCos();
	void recupereazaCos();
	void resetCos();

	friend istream& operator>>(istream& cin, Client& client);
	friend ostream& operator<<(ostream& cout, const Client& client);
};


