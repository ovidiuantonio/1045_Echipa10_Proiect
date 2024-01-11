#pragma once
#include "Produs.h"
#include <iostream>

class Laptop :public Produs {
private:
	int nivelBaterie;
	string modelProcesor;
	float memorieRAM;
public:
	Laptop();
	Laptop(int idProdus, int cantitate, float pret, float rating, string nume, string marca, string desciere, int nivelBaterie, string modelProcesor, float memorieRAM);

	string getNume();

	int getNivelBaterie();
	void setNivelBaterie(int nivelBaterie);

	float getmemorieRAM();
	void setmemorieRAM(float memorieRAM);

	string getModelProcesor();
	void setModelProcesor(string modelProcesor);

	virtual void afisareDetalii();
	virtual void editareProdus();

	virtual void serialize(ofstream& fout) const;
	virtual void deserialize(ifstream& fin);

};
