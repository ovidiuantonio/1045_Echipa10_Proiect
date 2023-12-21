#include <iostream>
#include <cstring>
#include "Produs.h"
#include "Client.h"
#include "Magazin.h"
#include "Subler.h"

using namespace std;

void vizualizareProduse(int nrProduseMagazin, Produs** produseMagazin) {
	cout << "Produsele disponibile in magazin sunt:\n";
	for (int i = 0; i < nrProduseMagazin; i++) {
		cout << i + 1 << ". " << produseMagazin[i]->getNume() << " " << produseMagazin[i]->getMarca() << "\n";
	}
}

int main() {
	string tipUser;

	int nrProduseMagazin = 1;
	Produs** produseMagazin = new Produs * [nrProduseMagazin];
	produseMagazin[0] = new Subler(10, 107, 4.89, "Subler", "sugubat", "Cei mai bun subler pentru mesterii adevarati!", "electric", "negru", 150);
	Magazin magazin("VOMMA");

	Client client("Ovidiu", "0752", 18);

	// primim tipul de utilizator si nu permitem introducerea altor valori in afar de C si A
	cout << "Cum vrei sa accesezi magazinul X? In calitate de Client (C) sau Administrator (A)?\n";
	while (cin >> tipUser) {
		tipUser[0] = toupper(tipUser[0]);
		if (tipUser != "C" && tipUser != "A") {
			cout << "Rol invalid! Te rog introdu din nou rolul dorit! Client (C) sau Administrator (A)\n";
		}
		else
			break;
	}

	
	if (tipUser == "C") {
		cout << "Bine ai venit in magazinul " << magazin.getNume() << "\n";

		while (1) {
			int optiune;
			cout << "\nCe doresti sa faci in magazinul nostru azi?\n";
			client.afiseazaMeniu();
			while (cin >> optiune) {
				client.afiseazaMeniu();
				if (optiune != 1 && optiune != 2 && optiune != 3 && optiune != 4 && optiune != 5 && optiune != 6 && optiune != 0)
					cout << "Optiune invalida! Te rugam sa introduci alta valoare!\n";
				else
					break;
			}

			// VA ROG SA FACETI OPTIUNILE IN FUNCTII DIFERITE!

			if (optiune == 1) {
				//1. Vizualizeaza produsele din magazin
				vizualizareProduse(nrProduseMagazin, produseMagazin);
				
			}
			else if (optiune == 2) {
				//2. Adauga produse in cos
			}
			else if (optiune == 3) {
				//3. Scoate produse din cos
			}
			else if (optiune == 4) {
				//4. Modifica datele personale
			}
			else if (optiune == 5) {
				//5. Trimite comanda
			}
			else if (optiune == 6) {
				//6. Vizualizeaza raportul ultimei comenzi trimise
			}
			else if (optiune == 0) {
				break;
			}
		}

	}
	

	return 0;
}