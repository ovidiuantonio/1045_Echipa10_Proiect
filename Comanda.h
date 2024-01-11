#pragma once
#include "Produs.h"
#include <iostream>
#include <vector> 
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
		int nrProduseComanda, int* cantitati, Produs** produseCosClient);
	~Comanda();

};



