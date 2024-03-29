#include "Subler.h"

Subler::Subler()
{
	nume = "Subler";
	tip = "electric";
	culoare = "negru";
	distantaMaxima = 100;
}

Subler::Subler(int idProdus, int cantitate, float pret, float rating, string nume, string marca, string desciere, string tip, string culoare, int distantaMaxima) : Produs(idProdus, cantitate, pret, rating, nume, marca, desciere)
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

string Subler::getNume()
{
	return nume;
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

void Subler::editareProdus() {
	this->Produs::editareProdus();
	cout << "Tip: ";
	getline(cin, tip);
	cout << "Culoare: ";
	getline(cin, culoare);
	cout << "Distanta maxima: ";
	while (cin >> distantaMaxima) {
		if (distantaMaxima <= 0)
			cout << "Valoare invalida! Introdu alta valoare: ";
		else
			break;
	}
}

void Subler::serialize(ofstream& fout) const {
	Produs::serialize(fout);
	fout.write((char*)&distantaMaxima, sizeof(distantaMaxima));

	int tipSize = tip.size();
	fout.write((char*)&tipSize, sizeof(tipSize));
	fout.write(tip.c_str(), tipSize);

	int culoareSize = culoare.size();
	fout.write((char*)&culoareSize, sizeof(culoareSize));
	fout.write(culoare.c_str(), culoareSize);
}

void Subler::deserialize(ifstream& fin) {
	Produs::deserialize(fin);
	fin.read((char*)&distantaMaxima, sizeof(distantaMaxima));

	int tipSize;
	fin.read((char*)&tipSize, sizeof(tipSize));
	char buffer[200]; 
	fin.read(buffer, tipSize);
	buffer[tipSize] = '\0';
	tip = buffer;

	int culoareSize;
	fin.read((char*)&culoareSize, sizeof(culoareSize));
	fin.read(buffer, culoareSize);
	buffer[culoareSize] = '\0';
	culoare = buffer;
}