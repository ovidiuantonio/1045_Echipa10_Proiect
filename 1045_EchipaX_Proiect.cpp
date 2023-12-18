#include <iostream>
#include "Produs.h"
#include "Client.h"
#include "Magazin.h"

using namespace std;

int main() {
	string tipUser;

	Produs** produseMagazin = new Produs * [5];
	Magazin magazin("VOMMA", 0, produseMagazin);

	Produs** cosClient = new Produs * [5];
	Client client("Ovidiu", "0752", 18, 0, 0, cosClient);

	// primim tipul de utilizator si nu permitem introducerea altor valori in afar de C si A
	cout << "Cum vrei sa accesezi magazinul X? In calitate de Client (C) sau Administrator (A)?\n";
	while (cin >> tipUser) {
		if (tipUser != "C" || tipUser != "A") {
			cout << "Rol invalid! Te rog introdu din nou rolul dorit! Client (C) sau Administrator (A)\n";
		}
	}
	
	if (tipUser == "C") {
		cout << "Bine ai venit in magazinul " << magazin.getNume() << "\n";

		while (1) {
			string optiune;
			cout << "\nCe doresti sa faci in magazinul nostru azi?\n";
			client.afiseazaMeniu();
			while (cin >> optiune) {
				if (optiune != "1" || optiune != "2" || optiune != "3" || optiune != "4" || optiune != "5" || optiune != "6" || optiune != "0")
					cout << "Optiune invalida! Te rugam sa introduci alta valoare!\n";
			}

			if (optiune == "1") {
				//1. Vizualizeaza produsele din magazin
			}
			else if (optiune == "2") {
				//2. Adauga produse in cos
			}
			else if (optiune == "3") {
				//3. Scoate produse din cos
			}
			else if (optiune == "4") {
				//4. Modifica datele personale
			}
			else if (optiune == "5") {
				//5. Trimite comanda
			}
			else if (optiune == "6") {
				//6. Vizualizeaza raportul ultimei comenzi trimise
			}
			else if (optiune == "0") {
				break;
			}
		}

	}
	

	return 0;
}