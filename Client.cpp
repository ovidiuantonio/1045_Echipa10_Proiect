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

Produs** Client::getProduseCosClient()
{
    return produseCosClient;
}

vector<int> Client::getCantitati()
{
    return cantitati;

}

void Client::salveazaCos()
{
    ofstream fout("ProduseCos.dat", ios::out | ios::trunc);

    //scriu nr de produse
    fout.write((char*)&nrProduseCos, sizeof(nrProduseCos));
    for (int i = 0; i < nrProduseCos; i++) {
        fout.write((char*)&cantitati[i], sizeof(cantitati[i]));
        int tip;
        string numeProdus = produseCosClient[i]->getNume();
        if (numeProdus == "Subler")
            tip = 1;
        else if (numeProdus == "Masina de tuns iarba")
            tip = 2;
        else if (numeProdus == "Bormasina")
            tip = 3;
        else if (numeProdus == "Laptop")
            tip = 4;
        else if (numeProdus == "Combina Frigorifica")
            tip = 5;

        //scriu tipul de produs
        fout.write((char*)&tip, sizeof(tip));
        //scriu produsul
        produseCosClient[i]->serialize(fout);
    }
    fout.close();
}

void Client::recupereazaCos()
{
    ifstream fin("ProduseCos.dat", ios::in);
    
    fin.read((char*)&nrProduseCos, sizeof(nrProduseCos));
    cantitati.resize(nrProduseCos);

    Produs** aux = new Produs * [nrProduseCos];

    for (int i = 0; i < nrProduseCos; i++) {
        fin.read((char*)&cantitati[i], sizeof(cantitati[i]));
        int tip;
        fin.read((char*)&tip, sizeof(tip));
        Produs* produs = nullptr;
        if (tip == 1)
            produs = new Subler;
        else if (tip == 2)
            produs = new MasinaDeTunsIarba;
        else if (tip == 3)
            produs = new Bormasina;
        else if (tip == 4)
            produs = new Laptop;
        else if (tip == 5)
            produs = new CombinaFrigorifica;

        //citesc produsul
        produs->deserialize(fin);
        aux[i] = produs;
    }

    produseCosClient = aux;
    fin.close();
}

void Client::resetCos()
{
    nrProduseCos = 0;
    produseCosClient = nullptr;
    cantitati.clear();

    Client::salveazaCos();
}

string Client::getTelefon()
{
    return telefon;
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

void Client::afiseazaMeniuUltimaComanda()
{
    system("CLS");
    cout << "--=== Raportul ultimei comenzi trimise ===--\n\n";
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

    Client::salveazaCos();
}

void Client::scoateProdusDinCos(int nrProdus)
{
    nrProduseCos = nrProduseCos - 1;
    Produs** aux = new Produs * [nrProduseCos];
    for (int j = 0; j < nrProdus; j++)
        aux[j] = produseCosClient[j];

    produseCosClient[nrProdus] = nullptr;

    for (int j = nrProdus; j < nrProduseCos; j++)
        aux[j] = produseCosClient[j + 1];

    delete[] produseCosClient;
    produseCosClient = aux;

    Client::salveazaCos();
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
