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
	marca = "Samsung";
	descriere = "Lorem Ipsum";
	idProdus = rand();
}

Produs::Produs(int idProdus, int cantitate, float pret, float rating, string nume, string marca, string desciere)
{
	this->idProdus = idProdus;
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
	cout << "Cantitate: ";
	cin>> cantitate;
	cout << "Pret: ";
	cin>> pret;
	cout << "Rating ( / 5): ";
	cin>> rating;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Marca: ";
	getline(cin, marca);
	cout << "Descriere: ";
	getline(cin, descriere);
}

void Produs::serialize(ofstream& fout) const {
	//asa scriu elementele de tip int, float etc, elem numerice
	fout.write((char*)&cantitate, sizeof(cantitate));
	fout.write((char*)&pret, sizeof(pret));
	fout.write((char*)&rating, sizeof(rating));

	// asa scriu elementele de tip string
	//le scriu marimea
	int numeSize = nume.size();
	fout.write((char*)&numeSize, sizeof(numeSize));
	//si dupa le scriu pe ele
	fout.write(nume.c_str(), numeSize);

	int marcaSize = marca.size();
	fout.write((char*)&marcaSize, sizeof(marcaSize));
	fout.write(marca.c_str(), marcaSize);

	int descriereSize = descriere.size();
	fout.write((char*)&descriereSize, sizeof(descriereSize));
	fout.write(descriere.c_str(), descriereSize);
}

void Produs::deserialize(ifstream& fin) {
	//asa citesc elem numerice
	fin.read((char*)&cantitate, sizeof(cantitate));
	fin.read((char*)&pret, sizeof(pret));
	fin.read((char*)&rating, sizeof(rating));

	// asa citesc elem de tip string
	int numeSize;
	fin.read((char*)&numeSize, sizeof(numeSize));
	char buffer[100];  
	fin.read(buffer, numeSize);
	buffer[numeSize] = '\0';
	nume = buffer;

	int marcaSize;
	fin.read((char*)&marcaSize, sizeof(marcaSize));
	fin.read(buffer, marcaSize);
	buffer[marcaSize] = '\0';
	marca = buffer;

	int descriereSize;
	fin.read((char*)&descriereSize, sizeof(descriereSize));
	fin.read(buffer, descriereSize);
	buffer[descriereSize] = '\0';
	descriere = buffer;
}
