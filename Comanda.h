#pragma once
#include "Produs.h"
#include "Subler.h"
#include "Bormasina.h"
#include "MasinaDeTunsIarba.h"
#include "Laptop.h"
#include "CombinaFrigorifica.h"
#include <iostream>
#include <vector> 
#include <cstdlib>
#include <string>

class Comanda
{
private:
	string comanda_id;
	vector<int> cantitati;
	int nrProduseComanda;
	Produs** produseComandaClient;
	float valoarea_totala;
	string nume_client;
	string telefon_client;
public:
	Comanda();
	Comanda(string comanda_id, string nume_client, string telefon_client,
		int nrProduseComanda, vector<int> cantitati, Produs** produseCosClient);
	~Comanda();

	int getNrProduseComanda();
	Produs** getProduseComandaClient();
	string getId();
	vector<int> getCantitati();

	void adaugaProdus(Produs* produs);

	virtual void serialize(ofstream& fout) const;
	virtual void deserialize(ifstream& fin);

	void writeFileComanda();
	void readFileComanda(ifstream& fin);

	friend ostream& operator<<(ostream& cout, const Comanda& comanda);
};



