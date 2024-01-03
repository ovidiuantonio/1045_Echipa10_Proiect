#pragma once
#include <iostream>

using namespace std;

class Produs
{
protected:
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
	string getNume();

	void setMarca(string marca);
	string getMarca();

	void setDescriere(string descriere);
	string getDescriere();

	//constructori
	Produs();
	Produs(int cantitate, float pret, float rating, string nume, string marca, string desciere);

	// metode virtuale de implementat pentru fiecare produs in parte
	virtual void afisareDetalii();
	virtual void editareProdus();
};

