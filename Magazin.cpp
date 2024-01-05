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
	delete[] produseMagazin;
}

string Magazin::getNume()
{
	return nume;
}

void Magazin::setNume(string nume)
{
	this->nume = nume;
}

int Magazin::getNrProduse()
{
	return nrProduseMagazin;
}

void Magazin::writeFileProduseMagazin() {
	ofstream fout("ProduseMagazin.dat", ios::out | ios::trunc);

	//scriu nr de produse
	fout.write((char*)&nrProduseMagazin, sizeof(nrProduseMagazin));
	for (int i = 0; i < nrProduseMagazin; i++) {
		int tip;
		string numeProdus = produseMagazin[i]->getNume();
		if (numeProdus == "Subler")
			tip = 1;
		else if (numeProdus == "Masina de tuns iarba")
			tip = 2;
		else if (numeProdus == "Bormasina")
			tip = 3;

		//scriu tipul de produs
		fout.write((char*)&tip, sizeof(tip));
		//scriu produsul
		produseMagazin[i]->serialize(fout);
	}
	fout.close();
}

void Magazin::readFileProduseMagazin() {
	ifstream fin("ProduseMagazin.dat", ios::in);

	//citesc nr de produse
	fin.read((char*)&nrProduseMagazin, sizeof(nrProduseMagazin));

	if (nrProduseMagazin < 0) {
		nrProduseMagazin = 0;
		produseMagazin = nullptr;
	}

	Produs** aux = new Produs * [nrProduseMagazin];

	for (int i = 0; i < nrProduseMagazin; i++) {
		//citesc tipul produsului
		int tip;
		fin.read((char*)&tip, sizeof(tip));
		Produs* produs = nullptr;
		if (tip == 1)
			produs = new Subler;
		else if (tip == 2)
			produs = new MasinaDeTunsIarba;
		else if (tip == 3)
			produs = new Bormasina;

		//citesc produsul
		produs->deserialize(fin);
		aux[i] = produs;
	}

	produseMagazin = aux;
	fin.close();
}

void Magazin::adaugaProdusMagazin(Produs* produs) {
	cout << nrProduseMagazin;
	Produs** aux = new Produs * [++nrProduseMagazin];
	for (int i = 0; i < nrProduseMagazin - 1; i++)
		aux[i] = produseMagazin[i];
	aux[nrProduseMagazin - 1] = produs;

	delete[] produseMagazin;
	produseMagazin = aux;

	//dupa ce adaug produsul updatez fisierul
	Magazin::writeFileProduseMagazin();
}

void Magazin::editareProdusMagazin(Produs* produs) {
	produs->editareProdus();
}

void Magazin::stergereProdusMagazin(Produs* produs) {
	int i;
	for (i = 0; i < nrProduseMagazin; i++) 
		if (produseMagazin[i] == produs)
			break;

	if (i <nrProduseMagazin)
	{
		nrProduseMagazin = nrProduseMagazin - 1;
		Produs** aux = new Produs * [nrProduseMagazin];
		for (int j = 0; j < i; j++)
			aux[j] = produseMagazin[j];
		for (int j = i; j < nrProduseMagazin; j++)
			aux[j] = produseMagazin[j + 1];

		delete[] produseMagazin;
		produseMagazin = aux;
	}

	//dupa ce sterg produsul updatez fisierul
	Magazin::writeFileProduseMagazin();
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

void Magazin::afiseazaMeniuAdauga()
{
	cout << "1. Adauga un subler\n2. Adauga o masina de tuns iarba\n3. Adauga o bormasina\n\n\n0. Inapoi\n";
}

Magazin Magazin::operator-=(Produs* p) {
	int i;
	for (i = 0; i < nrProduseMagazin; i++)
		if (produseMagazin[i] == p)
			break;

	if (i < nrProduseMagazin)
	{
		nrProduseMagazin = nrProduseMagazin - 1;
		Produs** aux = new Produs * [nrProduseMagazin];
		for (int j = 0; j < i; j++)
			aux[j] = produseMagazin[j];
		for (int j = i; j < nrProduseMagazin; j++)
			aux[j] = produseMagazin[j + 1];

		delete[] produseMagazin;
		produseMagazin = aux;
	}

	//dupa ce sterg produsul updatez fisierul
	Magazin::writeFileProduseMagazin();

	return *this;
}

Produs* Magazin::getProdus(int index) {
	return produseMagazin[index];
}