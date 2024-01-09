#include "Client.h"

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
    cout << "1. Vizualizeaza produsele din magazin\n2. Adauga produse in cos\n3. Scoate produse din cos\n4. Modifica datele personale\n5. Trimite comanda\n6. Vizualizeaza raportul ultimei comenzi trimise\n\n\n0. Inchide aplicatia\n";
}

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

void Client::afisareCos()
{
    cout << "Cosul lui " << nume << " este:\n";
    for (int i = 0; i < nrProduseCos; i++) {
        cout << i + 1 << ". " << produseCosClient[i]->getNume() << " " << produseCosClient[i]->getMarca() << " x " << cantitati[i] << " buc. \n";
    }
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
