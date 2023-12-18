#include "Subler.h"

Subler::Subler()
{
	tip = "electric";
	culoare = "negru";
	distantaMaxima = 100;
}

Subler::Subler(int cantitate, float pret, float rating, string nume, string marca, string desciere, string tip, string culoare, int distantaMaxima) : Produs(cantitate, pret, rating, nume, marca, desciere)
{
	this->tip = tip;
	this->culoare = culoare;
	if(distantaMaxima > 0)
		this->distantaMaxima = distantaMaxima;
}

void Subler::setTip(string tip)
{
	this->tip = tip;
}

string Subler::getTip()
{
	return tip;
}

void Subler::setCuloare(string culoare)
{
	this->culoare = culoare;
}

string Subler::getCuloare()
{
	return culoare;
}

void Subler::setDistantaMaxima(int distantaMaxima)
{
	if (distantaMaxima > 0)
		this->distantaMaxima = distantaMaxima;
}

int Subler::getDistantaMaxima()
{
	return distantaMaxima;
}

void Subler::afisareDetalii()
{
	cout << "Sublerul " << nume << "este de tip " << tip << ", are culoarea " << culoare << " si poate masura la o distanta maxima de " << distantaMaxima << "mm. Are pretul de " << pret << "lei si are un rating de " << rating << "/ 5 stele. Cantitatea disponibila este de " << cantitate << " bucati!\n" << descriere << "\n";
}
