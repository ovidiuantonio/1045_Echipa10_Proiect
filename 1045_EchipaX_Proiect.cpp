#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "Produs.h"
#include "Client.h"
#include "Magazin.h"
#include "Subler.h"
#include "MasinaDeTunsIarba.h"
#include "Bormasina.h"

using namespace std;

int main() {
	string tipUser;

	Magazin magazin("VOMMA", 0, nullptr);
	magazin.readFileProduseMagazin();
	
	Client client("Ovidiu", "0752925119", 18, 0, nullptr, nullptr);

	// primim tipul de utilizator si nu permitem introducerea altor valori in afar de C si A
	system("CLS");
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
		system("CLS");
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
				system("CLS");
				magazin.vizualizareProduse();
			}
			else if (optiune == 2) {
				//2. Adauga produse in cos
				// similar cu adauga produse in magazin, doar ca se afce pe partea de client
				// cand se adauga un produs in cos se scade din cantitatea disp in magazin
				system("CLS");
				system("CLS");
				cout << "\nCe produs vrei sa adaugi in cos?\n";
				magazin.vizualizareProduse();
				int nrProdus;
				while (cin >> nrProdus) {
					if (nrProdus < 1 && nrProdus > magazin.getNrProduse())
						cout << "Optiune invalida!Te rugam sa introduci alta valoare!\n";
					else
						break;
				}

				nrProdus--;
			}
			else if (optiune == 3) {
				//3. Scoate produse din cos
				// cand se sterge un produs in cos se mareste cantitatea disp in magazin
				system("CLS");
				cout << "\nCe produs vrei sa scoti din cos?\n";
				client.afisareCos();
				int nrProdus;
				while (cin >> nrProdus) {
					if (nrProdus < 1 && nrProdus > client.getNrProduseCos())
						cout << "Optiune invalida!Te rugam sa introduci alta valoare!\n";
					else
						break;
				}

				nrProdus--;
				// supraincarca [] pentru stergere
				//client[nrProdus]
			}
			else if (optiune == 4) {
				//4. Modifica datele personale
				system("CLS");
				cout << "Modifica datele personale:\n";
				cin >> client;
				cout << "\nDatele tale au fost modificate astfel:\n";
				cout << client;
			}
			else if (optiune == 5) {
				//5. Trimite comanda
				// se instantiaza clasa comanda si se adauga cosul, cantitatile, nr de produse si datele clientului
				// se scrie intr-un fisier comanda
				system("CLS");
			}
			else if (optiune == 6) {
				//6. Vizualizeaza raportul ultimei comenzi trimise
				// se citeste din fisier comanda trimisa
				system("CLS");
			}
			else if (optiune == 0) {
				break;
			}
		}

	}
	else {
		system("CLS");
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
				while (1) {
					//1. Adauga produse in magazin
					Produs* produs;
					int optiuneAdauga;
					system("CLS");
					cout << "\nCe produs doresti sa adaugi?\n";
					magazin.afiseazaMeniuAdauga();
					while (cin >> optiuneAdauga) {
						if (optiune != 1 && optiune != 2 && optiune != 3 && optiune != 0)
							cout << "Optiune invalida! Te rugam sa introduci alta valoare!\n";
						else
							break;
					}

					if (optiuneAdauga == 1) {
						produs = new Subler;
					}
					else if (optiuneAdauga == 2) {
						produs = new MasinaDeTunsIarba;
					}
					else if (optiuneAdauga == 3) {
						produs = new Bormasina;
					}
					else {
						break;
					}

					produs->editareProdus();
					magazin.adaugaProdusMagazin(produs);
					cout << "Produsul a fost adaugat cu succes!\n";
				}
			}
			else if (optiune == 2) {
				//2. Editare Produse magazin
				//operator []
				system("CLS");
				magazin.vizualizareProduse();
				cout << "\nIntrodu numarul produsului pe care doresti sa-l editezi:\n";
				int nrProdus;
				while (cin >> nrProdus) {
					if (nrProdus < 1 && nrProdus > magazin.getNrProduse())
						cout << "Valoarea introdusa nu face parte din lista!";
					else
						break;
				}

				//decrementez pentru a potrivi val introdusa cu indexul produsului
				nrProdus--;
				magazin.getProdus(nrProdus)->editareProdus();
				magazin.writeFileProduseMagazin();
			}
			else if (optiune == 3) {
				//3. Sterge produse magazin
				system("CLS");
				magazin.vizualizareProduse();
				cout << "\nIntrodu numarul produsului pe care doresti sa-l stergi:\n";
				int nrProdus;
				while (cin >> nrProdus) {
					if (nrProdus < 1 && nrProdus > magazin.getNrProduse())
						cout << "Valoarea introdusa nu face parte din lista!";
					else
						break;
				}

				nrProdus--;
				//magazin[nrProdus];

				magazin.writeFileProduseMagazin();
			}
			else if (optiune == 4) {
				//4. Prelucrare comenzi
				// se afiseaza comenzile primite
			}
			else if (optiune == 5) {
				//5. Raport comenzi
				// se scriu toate comenzile intr-un fisier
			}
			else if (optiune == 0) {
				break;
			}
		}
	}
	

	return 0;
}