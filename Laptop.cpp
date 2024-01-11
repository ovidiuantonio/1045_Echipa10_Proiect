#include "Laptop.h";
using namespace std;

Laptop::Laptop() {
	nume = "Laptop";
	nivelBaterie = 100;
	modelProcesor = "Intel";
	memorieRAM = 5;
}

Laptop::Laptop(int idProdus, int cantitate, float pret, float rating, string nume, string marca, string desciere, int nivelBaterie, string modelProcesor, float memorieRAM)
	:Produs(idProdus, cantitate, pret, rating, nume, marca, descriere)
{
	this->nivelBaterie = nivelBaterie;
	this->memorieRAM = memorieRAM;
	this->modelProcesor = modelProcesor;
}

string Laptop::getNume()
{
	return nume;
}

int Laptop::getNivelBaterie() {
	return this->nivelBaterie;
}
void Laptop::setNivelBaterie(int nivelBaterie) {
	this->nivelBaterie = nivelBaterie;
}

float Laptop::getmemorieRAM() {
	return this->memorieRAM;
}
void Laptop::setmemorieRAM(float memorieRAM) {
	this->memorieRAM = memorieRAM;
}

string Laptop::getModelProcesor() {
	return this->modelProcesor;
}
void Laptop::setModelProcesor(string modelProcesor) {
	this->modelProcesor = modelProcesor;
}

void Laptop::editareProdus() {
	this->Produs::editareProdus();
	cout << "Nivel Baterie:";
	cin >> nivelBaterie;
	cout << "Memorie RAM:";
	cin >> memorieRAM;
	cout << "Model Procesor:";
	cin >> modelProcesor;
}

void Laptop::afisareDetalii() {
	this->Produs::afisareDetalii();
	cout << "Nivel Baterie: " << nivelBaterie << endl;
	cout << "Memorie RAM: " << memorieRAM << endl;
	cout << "Model Procesor: " << modelProcesor << endl;
}

void Laptop::serialize(ofstream& fout) const {
	Produs::serialize(fout);

	int size = modelProcesor.size();
	fout.write((char*)&size, sizeof(size));
	fout.write(modelProcesor.c_str(), size);

	fout.write((char*)&nivelBaterie, sizeof(nivelBaterie));
	fout.write((char*)&memorieRAM, sizeof(memorieRAM));
}

void Laptop::deserialize(ifstream& fin)
{
	Produs::deserialize(fin);

	int Size;
	fin.read((char*)&Size, sizeof(Size));
	char buffer[100];
	fin.read(buffer, Size);
	buffer[Size] = '\0';
	modelProcesor = buffer;

	fin.read((char*)&nivelBaterie, sizeof(nivelBaterie));
	fin.read((char*)&memorieRAM, sizeof(memorieRAM));
}

