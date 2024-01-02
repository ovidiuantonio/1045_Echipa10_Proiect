#include "Client.h"

string Client::getNume()
{
    return nume;
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
    cantitati = nullptr;
    produseCosClient = nullptr;
}

Client::Client(string nume, string telefon, int varsta, int nrProduseCos, int* cantitati, Produs** produseCosClient)
{
    this->nume = nume;
    this->telefon = telefon;
    this->varsta = varsta;
    this->nrProduseCos = nrProduseCos;

    if (nrProduseCos != 0) {
        this->cantitati = new int [nrProduseCos];
        this->produseCosClient = new Produs * [nrProduseCos];
        for (int i = 0; i < nrProduseCos; i++) {
            this->cantitati[i] = cantitati[i];
            this->produseCosClient[i] = produseCosClient[i];
        }
    }
    else {
        cantitati = nullptr;
        produseCosClient = nullptr;
    }
}

Client::~Client()
{
    for (int i = 0; i < nrProduseCos - 1; i++)
        delete produseCosClient[i];

    delete[] produseCosClient;
    delete[] cantitati;
}

void Client::afisareCos()
{
    cout << "Cosul lui " << nume << " este:\n";
    for (int i = 0; i < nrProduseCos; i++) {
        cout << i + 1 << ". " << produseCosClient[i]->getNume() << " " << produseCosClient[i]->getMarca() << "\n";
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
