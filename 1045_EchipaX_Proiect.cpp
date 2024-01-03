#include <iostream>
#include <cstring>
#include "Produs.h"
#include "Client.h"
#include "Magazin.h"
#include "Subler.h"
#include "MasinaDeTunsIarba.h"

using namespace std;

int main() {
	string tipUser;

	Magazin magazin("VOMMA", 0, nullptr);
	magazin.readFileProduseMagazin();
	
	Client client("Ovidiu", "0752925119", 18, 0, nullptr, nullptr);

	// primim tipul de utilizator si nu permitem introducerea altor valori in afar de C si A
	cout << "Cum vrei sa accesezi magazinul " << magazin.getNume() << "? In calitate de Client(C) sau Administrator(A) ? \n";
	while (cin >> tipUser) {
		tipUser[0] = toupper(tipUser[0]);
		if (tipUser != "C" && tipUser != "A") {
			cout << "Rol invalid! Te rog introdu din nou rolul dorit! Client (C) sau Administrator (A)\n";
		}
		else
			break;
	}

	
	if (tipUser == "C") {
		cout << "Bine ai venit in magazinul " << magazin.getNume() << ", " << client.getNume() << "\n";

		while (1) {
			int optiune;
			cout << "\nCe doresti sa faci in magazinul nostru azi?\n";
			client.afiseazaMeniu();
			while (cin >> optiune) {
				if (optiune != 1 && optiune != 2 && optiune != 3 && optiune != 4 && optiune != 5 && optiune != 6 && optiune != 0)
					cout << "Optiune invalida! Te rugam sa introduci alta valoare!\n";
				else
					break;
			}

			// VA ROG SA FACETI OPTIUNILE IN FUNCTII DIFERITE!

			if (optiune == 1) {
				//1. Vizualizeaza produsele din magazin
				magazin.vizualizareProduse();
			}
			else if (optiune == 2) {
				//2. Adauga produse in cos
			}
			else if (optiune == 3) {
				//3. Scoate produse din cos
			}
			else if (optiune == 4) {
				//4. Modifica datele personale
				cin >> client;
				cout << "\nDatele tale au fost modificate astfel:\n";
				cout << client;
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
	else {
		cout << "Bine ai venit in magazinul " << magazin.getNume() << "\n";

		while (1) {
			int optiune;
			cout << "\nCe doresti sa faci in magazinul nostru azi?\n";
			magazin.afiseazaMeniu();
			while (cin >> optiune) {
				if (optiune != 1 && optiune != 2 && optiune != 3 && optiune != 4 && optiune != 5 && optiune != 0)
					cout << "Optiune invalida! Te rugam sa introduci alta valoare!\n";
				else
					break;
			}

			// VA ROG SA FACETI OPTIUNILE IN FUNCTII DIFERITE!

			if (optiune == 1) {
				//1. Adauga produse in magazin
				Produs* produs;
				int optiuneAdauga;
				cout << "\nCe produs doresti sa adaugi?\n";
				magazin.afiseazaMeniuAdauga();
				while (cin >> optiuneAdauga) {
					if (optiune != 1 && optiune != 2 && optiune != 0)
						cout << "Optiune invalida! Te rugam sa introduci alta valoare!\n";
					else
						break;
				}

				if (optiuneAdauga == 1) {
					produs = new Subler;
				} else if (optiuneAdauga == 2) {
					produs = new MasinaDeTunsIarba;
				}
				else {
					break;
				}

				produs->editareProdus();
				magazin.adaugaProdusMagazin(produs);
				cout << "Produsul a fost adaugat cu succes!\n";

				delete produs;
				produs = nullptr;
			}
			else if (optiune == 2) {
				//2. Editare Produse magazin
				//operator []
			}
			else if (optiune == 3) {
				//3. Sterge produse magazin
			}
			else if (optiune == 4) {
				//4. Prelucrare comenzi
			}
			else if (optiune == 5) {
				//5. Raport comenzi
			}
			else if (optiune == 0) {
				break;
			}
		}
	}
	

	return 0;
}