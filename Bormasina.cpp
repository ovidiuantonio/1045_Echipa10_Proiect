#include "Bormasina.h"

Bormasina::Bormasina()
{
    nume = "Bormasina";
    tipAlimentare = "electric";
    putere = 500;
    areBateriaInclusa = 0;
}

Bormasina::Bormasina(int idProdus, int cantitate, float pret, float rating, string nume, string marca, string descriere, string tipAlimentare, int putere, int areBateriaInclusa)
    : Produs(idProdus, cantitate, pret, rating, nume, marca, descriere)
{
    this->tipAlimentare = tipAlimentare;
    this->putere = putere;
    this->areBateriaInclusa = areBateriaInclusa;
}

string Bormasina::getNume()
{
    return nume;
}

void Bormasina::setTipAlimentare(string tipAlimentare)
{
    this->tipAlimentare = tipAlimentare;
}

string Bormasina::getTipAlimentare()
{
    return tipAlimentare;
}

void Bormasina::setPutere(int putere)
{
    if (putere > 0)
        this->putere = putere;
}

int Bormasina::getPutere()
{
    return putere;
}

void Bormasina::setAreBateriaInclusa(bool areBateriaInclusa)
{
    this->areBateriaInclusa = areBateriaInclusa;
}

int Bormasina::getAreBateriaInclusa()
{
    return areBateriaInclusa;
}

void Bormasina::afisareDetalii()
{
    cout << "Bormasina " << nume << " este de tip " << tipAlimentare << ", are puterea de " << putere << " W si " << (areBateriaInclusa ? "include" : "nu include") << " baterie. Are pretul de " << pret << " lei si are un rating de " << rating << "/5 stele. Cantitatea disponibila este de " << cantitate << " bucati!\n" << descriere << "\n";
}

void Bormasina::editareProdus() {
    this->Produs::editareProdus();
    cout << "Tip alimentare: ";
    getline(cin, tipAlimentare);
    cout << "Putere: ";
    cin >> putere;
    cout << "Are baterie inclusa (1 / 0): ";
    cin >> areBateriaInclusa;
}

void Bormasina::serialize(ofstream& fout) const {
    Produs::serialize(fout);

    int tipSize = tipAlimentare.size();
    fout.write((char*)&tipSize, sizeof(tipSize));
    fout.write(tipAlimentare.c_str(), tipSize);

    fout.write((char*)&putere, sizeof(putere));
    fout.write((char*)&areBateriaInclusa, sizeof(areBateriaInclusa));
}

void Bormasina::deserialize(ifstream& fin) {
    Produs::deserialize(fin);

    int tipSize;
    fin.read((char*)&tipSize, sizeof(tipSize));
    char buffer[200]; 
    fin.read(buffer, tipSize);
    buffer[tipSize] = '\0';
    tipAlimentare = buffer;

    fin.read((char*)&putere, sizeof(putere));
    fin.read((char*)&areBateriaInclusa, sizeof(areBateriaInclusa));
}