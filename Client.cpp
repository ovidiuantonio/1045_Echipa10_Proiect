#include "Client.h"

Client::Client() {
    nume = "Ovidiu";
    telefon = "0752925119";
    varsta = 20;
    nrProduseCos = 0;
    cantitati.resize(0);
    produseCosClient = nullptr;
}

Client::Client(string nume, string telefon, int varsta, int nrProduseCos, int* cantitati, Produs** produseCosClient)
{
    this->nume = nume;
    this->telefon = telefon;
    this->varsta = varsta;
    this->nrProduseCos = nrProduseCos;

    if (nrProduseCos != 0) {
        this->cantitati.clear();
        this->cantitati.resize(nrProduseCos);
        this->produseCosClient = new Produs * [nrProduseCos];
        for (int i = 0; i < nrProduseCos; i++) {
            this->cantitati.push_back(cantitati[i]);
            this->produseCosClient[i] = produseCosClient[i];
        }
    }
    else {
        this->cantitati.resize(0);
        this->produseCosClient = nullptr;
    }
}

Client::~Client()
{
    delete[] produseCosClient;
    cantitati.clear();
}

string Client::getNume()
{
    return nume;
}

int Client::getNrProduseCos()
{
    return nrProduseCos;
}

void Client::afiseazaMeniu()
{
    system("CLS");
    cout << "--=== Bine ai venit " << nume << "! Ce doresti sa faci in magazinul nostru azi ? ===--\n\n";
    cout << "1. Vizualizeaza produsele din magazin\n2. Adauga produse in cos\n3. Scoate produse din cos\n4. Modifica datele personale\n5. Trimite comanda\n6. Vizualizeaza raportul ultimei comenzi trimise\n\n\n0. Inchide aplicatia\n";
}

void Client::afiseazaMeniuAdauga()
{
    system("CLS");
    cout << "--=== Adauga un produs in cos ===--\n\n";
}

void Client::afiseazaMeniuSterge()
{
    system("CLS");
    cout << "--=== Sterge un produs in cos ===--\n\n";
}

void Client::afiseazaMeniuEditare()
{
    system("CLS");
    cout << "--=== Editeaza datele personale ===--\n\n";
}

void Client::afiseazaMeniuProduseMagazin()
{
    system("CLS");
    cout << "--=== Acestea sunt produsele disponibile in magazin ===--\n\n";
}

void Client::afisareCos()
{
    cout << "Cosul lui " << nume << " este:\n";
    for (int i = 0; i < nrProduseCos; i++) {
        cout << i + 1 << ". " << produseCosClient[i]->getNume() << " " << produseCosClient[i]->getMarca() << " x " << cantitati[i] << " buc. \n";
    }
}

void Client::adaugaProdusInCos(Produs* produs, int cantitate) {
    cantitati.push_back(cantitate);
    Produs** aux = new Produs * [nrProduseCos + 1];
    for (int i = 0; i < nrProduseCos; i++) {
        aux[i] = produseCosClient[i];
    }
    aux[nrProduseCos] = produs;
    nrProduseCos++;
    delete[] produseCosClient;
    produseCosClient = aux;
}

istream& operator>>(istream& cin, Client& client) {
    cout << "Nume: ";
    cin >> client.nume;
    cout << "Telefon: ";
    cin >> client.telefon;
    cout << "Varsta: ";
    cin >> client.varsta;

    return cin;
}

ostream& operator<<(ostream& cout, const Client& client)
{
    cout << "Nume: ";
    cout << client.nume << "\n";
    cout << "Telefon: ";
    cout << client.telefon << "\n";
    cout << "Varsta: ";
    cout << client.varsta << "\n";

    return cout;
}
