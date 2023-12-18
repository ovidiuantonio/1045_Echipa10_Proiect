#include "Client.h"

string Client::getNume()
{
    return nume;
}

void Client::afiseazaMeniu()
{
    cout << "1. Vizualizeaza produsele din magazin\n2. Adauga produse in cos\n3. Scoate produse din cos\n4. Modifica datele personale\n5. Trimite comanda\n6. Vizualizeaza raportul ultimei comenzi trimise\n\n\n0. Inchide aplicatia\n";
}

Client::Client()
{
}

Client::Client(string nume, string telefon, int varsta)
{
}

Client::~Client()
{
}

void Client::afisareCos()
{
}

void Client::setDateClient() {

}
