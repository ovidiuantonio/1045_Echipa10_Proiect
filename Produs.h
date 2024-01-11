#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

class Produs
{
protected:
	int idProdus;
	int cantitate;
	float pret;
	float rating;
	string nume;
	string marca;
	string descriere;
public:
	// getteri si setteri
	void setCantitate(int cantitate);
	int getCantitate();

	void setPret(float pret);
	float getPret();

	void setRating(float rating);
	float getRating();

	void setNume(string nume);

	//de implementat pentru fiecare produs
	virtual string getNume();

	void setMarca(string marca);
	string getMarca();

	void setDescriere(string descriere);
	string getDescriere();

	int getId();

	//constructori
	Produs();
	Produs(int idProdus, int cantitate, float pret, float rating, string nume, string marca, string desciere);

	// metode virtuale de implementat pentru fiecare produs in parte
	virtual void afisareDetalii();
	virtual void editareProdus();

	//metoda folosita pentru a scrie in fisier - de implementat pentru toate clasele!!
	virtual void serialize(ofstream& fout) const;
	//metoda folosita pentru a citi din fisier - de implementat pentru toate clasele!!
	virtual void deserialize(ifstream& fin);
};

