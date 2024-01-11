#include "CombinaFrigorifica.h"

CombinaFrigorifica::CombinaFrigorifica()
{
    nume = "Combina Frigorifica";
    capacitateCongelare = 10;
    greutate = 56;
    culoare = "alb";
}

CombinaFrigorifica::CombinaFrigorifica(int idProdus, int cantitate, float pret, float rating, string nume, string marca, string descriere, int capacitateCongelare, int greutate, string culoare)
    : Produs(idProdus, cantitate, pret, rating, nume, marca, descriere)
{
    this->capacitateCongelare = capacitateCongelare;
    this->greutate = greutate;
    this->culoare = culoare;
}

void CombinaFrigorifica::setCapacitateCongelare(int capacitateCongelare)
{
    this->capacitateCongelare = capacitateCongelare;
}

int CombinaFrigorifica::getCapacitateCongelare()
{
    return capacitateCongelare;
}

void CombinaFrigorifica::setGreutate(int greutate)
{
    this->greutate = greutate;
}

int CombinaFrigorifica::getGreutate()
{
    return greutate;
}

void CombinaFrigorifica::setCuloare(string culoare)
{
    this->culoare = culoare;
}

string CombinaFrigorifica::getCuloare()
{
    return culoare;
}

string CombinaFrigorifica::getNume()
{
    return nume;
}

void CombinaFrigorifica::afisareDetalii()
{
    cout << "Combina frigorifica " << nume << " are capacitatea de congelare de " << capacitateCongelare << " kg/24h, o greutate de " << greutate << " kg si culoarea " << culoare << ". Are pretul de " << pret << " lei si are un rating de " << rating << "/5 stele. Cantitatea disponibila este de " << cantitate << " bucati!\n"
        << descriere << "\n";
}

void CombinaFrigorifica::editareProdus()
{
    this->Produs::editareProdus();
    cout << "Capacitate congelare: ";
    cin >> capacitateCongelare;
    cout << "Greutate: ";
    cin >> greutate;
    cout << "Culoare: ";
    getline(cin, culoare);
}

void CombinaFrigorifica::serialize(ofstream& fout) const
{
    Produs::serialize(fout);
    fout.write((char*)&capacitateCongelare, sizeof(capacitateCongelare));
    fout.write((char*)&greutate, sizeof(greutate));

    int culoareSize = culoare.size();
    fout.write((char*)&culoareSize, sizeof(culoareSize));
    fout.write(culoare.c_str(), culoareSize);
}

void CombinaFrigorifica::deserialize(ifstream& fin)
{
    Produs::deserialize(fin);
    fin.read((char*)&capacitateCongelare, sizeof(capacitateCongelare));
    fin.read((char*)&greutate, sizeof(greutate));

    int culoareSize;
    fin.read((char*)&culoareSize, sizeof(culoareSize));
    char buffer[100];
    fin.read(buffer, culoareSize);
    buffer[culoareSize] = '\0';
    culoare = buffer;
}