#include "Produs.h"

void Produs::setCantitate(int cantitate)
{
	if (cantitate >= 0)
		this->cantitate = cantitate;
}

int Produs::getCantitate()
{
	return cantitate;
}

void Produs::setPret(float pret)
{
	if (pret > 0)
		this->pret = pret;
}

float Produs::getPret()
{
	return pret;
}

void Produs::setRating(float rating)
{
	if (rating > 0 && rating <= 5)
		this->rating = rating;
}

float Produs::getRating()
{
	return rating;
}

void Produs::setNume(string nume)
{
	this->nume = nume;
}

string Produs::getNume()
{
	return nume;
}

void Produs::setMarca(string marca)
{
	this->marca = marca;
}

string Produs::getMarca()
{
	return marca;
}

void Produs::setDescriere(string descriere)
{
	this->descriere = descriere;
}

string Produs::getDescriere()
{
	return descriere;
}

Produs::Produs()
{
	cantitate = 0;
	pret = 1;
	rating = 1;
	nume = "Produs-Default";
	marca = "Samsung";
	descriere = "Lorem Ipsum";
}

Produs::Produs(int cantitate, float pret, float rating, string nume, string marca, string desciere)
{
	if(cantitate >= 0)
		this->cantitate = cantitate;
	if (pret > 0)
		this->pret = pret;
	if (rating > 0 && rating <= 5)
		this->rating = rating;
	this->nume = nume;
	this->marca = marca;
	this->descriere = desciere;
}

void Produs::afisareDetalii()
{
	cout << descriere << "\n";
}

void Produs::editareProdus() {
	cin>> cantitate;
	cin>> pret;
	cin>> rating;
	cin>> nume;
	cin>> marca;
	cin>> descriere;
}
