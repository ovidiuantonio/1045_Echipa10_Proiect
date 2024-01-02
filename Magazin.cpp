#include "Magazin.h"


Magazin::Magazin() {
	nume = "Default";
	nrProduseMagazin = 0;
	produseMagazin = nullptr;
}

Magazin::Magazin(string nume, int nrProduseMagazin, Produs** produseMagazin)
{
	this->nume = nume;
	this->nrProduseMagazin = nrProduseMagazin;
	
	if (nrProduseMagazin != 0) {
		produseMagazin = new Produs * [nrProduseMagazin];

		for (int i = 0; i < nrProduseMagazin; i++)
			this->produseMagazin[i] = produseMagazin[i];
	}
	else
		produseMagazin = nullptr;
}

Magazin::~Magazin()
{
	for (int i = 0; i < nrProduseMagazin - 1; i++)
		delete produseMagazin[i];

	delete[] produseMagazin;
}

string Magazin::getNume()
{
	return nume;
}

Produs** Magazin::getProduseMagazin()
{
	return produseMagazin;
}

void Magazin::setNume(string nume)
{
	this->nume = nume;
}

void Magazin::adaugaProdusMagazin(Produs* produs) {
	Produs** aux = new Produs * [++nrProduseMagazin];
	for (int i = 0; i < nrProduseMagazin - 1; i++)
		aux[i] = produseMagazin[i];
	aux[nrProduseMagazin - 1] = produs;

	for (int i = 0; i < nrProduseMagazin - 1; i++)
		delete produseMagazin[i];

	delete[] produseMagazin;
	produseMagazin = aux;
}

void Magazin::vizualizareProduse() {
	cout << "Produsele disponibile in magazin sunt:\n";
	for (int i = 0; i < nrProduseMagazin; i++) {
		cout << i + 1 << ". " << produseMagazin[i]->getNume() << " " << produseMagazin[i]->getMarca() << "\n";
	}
}

void Magazin::afiseazaMeniu()
{
	cout << "1. Adauga un produs in magazin\n2. Editeaza un produs din magazin\n3. Sterge un produs din magazin\n4. Prelucreaza comenzile\n5. Realizeaza raportul tuturor comenzilor\n\n\n0. Inchide aplicatia\n";
}
