#include "Comanda.h"

Comanda::Comanda()
{
	comanda_id = "0";
	cantitati.resize(0);
	nrProduseComanda = 0;
	produseComandaClient = nullptr;
	valoarea_totala = 0;
	nume_client = "Ovidiu";
	telefon_client = "0752925119";
}

Comanda::Comanda(string comanda_id, string nume_client, string telefon_client, int nrProduseComanda, int* cantitati, Produs** produseCosClient)
{
	this->comanda_id = comanda_id;
    valoarea_totala = 0;
	this->nume_client = nume_client;
	this->telefon_client = telefon_client;
    if (nrProduseComanda != 0) {
        this->cantitati.clear();
        this->cantitati.resize(nrProduseComanda);
        this->produseComandaClient = new Produs * [nrProduseComanda];
        for (int i = 0; i < nrProduseComanda; i++) {
            this->cantitati.push_back(cantitati[i]);
            this->produseComandaClient[i] = produseComandaClient[i];
            valoarea_totala += cantitati[i] * produseComandaClient[i]->getPret();
        }
    }
    else {
        this->cantitati.resize(0);
        this->produseComandaClient = nullptr;
    }

}

Comanda::~Comanda()
{
    delete[] produseComandaClient;
    cantitati.clear();
}
