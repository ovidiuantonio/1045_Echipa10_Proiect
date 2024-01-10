#include <iostream>
#include "Produs.h"
#include "Client.h"
#include "Magazin.h"
#include "Subler.h"
#include "MasinaDeTunsIarba.h"
#include "Bormasina.h"
#include "Laptop.h"

using namespace std;

int main() {
	string tipUser;

	Magazin magazin("MAMOV", 0, nullptr);
	magazin.readFileProduseMagazin();

	IMagazin* interfataMagazin = &magazin;
	
	Client client("Ovidiu", "0752925119", 18, 0, nullptr, nullptr);
	IMagazin* interfataClient = &client;

	// primim tipul de utilizator si nu permitem introducerea altor valori in afar de C si A
	system("CLS");
	cout << "Cum vrei sa accesezi magazinul " << magazin.getNume() << "? In calitate de Client (C) sau Administrator (A) ? \n";
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
			interfataClient->afiseazaMeniu();
			while (cin >> optiune) {
				if (optiune != 1 && optiune != 2 && optiune != 3 && optiune != 4 && optiune != 5 && optiune != 6 && optiune != 0)
					cout << "Optiune invalida! Te rugam sa introduci alta valoare!\n";
				else
					break;
			}

			// VA ROG SA FACETI OPTIUNILE IN FUNCTII DIFERITE!

			if (optiune == 1) {
				//1. Vizualizeaza produsele din magazin
				interfataClient->afiseazaMeniuProduseMagazin();
				magazin.vizualizareProduse();

				cout << "\n0. Inapoi\n";
				int back;
				while (cin >> back) {
					if (back != 0)
						cout << "Daca nu introduci valoarea 0 nu te vei mai putea intoarce niciodata! * ^ *\n";
					else
						break;
				}

			}
			else if (optiune == 2) {
				//2. Adauga produse in cos
				// similar cu adauga produse in magazin, doar ca se afce pe partea de client
				// cand se adauga un produs in cos se scade din cantitatea disp in magazin
				interfataClient->afiseazaMeniuAdauga();
				magazin.vizualizareProduse();
				cout << "\nIntrodu o valoare: ";
				int nrProdus;
				while (cin >> nrProdus) {
					if (nrProdus < 1 && nrProdus > magazin.getNrProduse())
						cout << "Optiune invalida! Te rugam sa introduci alta valoare!\n";
					else
						break;
				}

				nrProdus--;

				// cod

				cout << "\nProdusul a fost adaugat cu succes!\n";

				cout << "\n0. Inapoi\n";
				int back;
				while (cin >> back) {
					if (back != 0)
						cout << "Daca nu introduci valoarea 0 nu te vei mai putea intoarce niciodata! * ^ *\n";
					else
						break;
				}
			}
			else if (optiune == 3) {
				//3. Scoate produse din cos
				// cand se sterge un produs in cos se mareste cantitatea disp in magazin
				interfataClient->afiseazaMeniuSterge();
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

				cout << "\nProdusul a fost scos din cos cu succes!\n";

				cout << "\n0. Inapoi\n";
				int back;
				while (cin >> back) {
					if (back != 0)
						cout << "Daca nu introduci valoarea 0 nu te vei mai putea intoarce niciodata! * ^ *\n";
					else
						break;
				}
			}
			else if (optiune == 4) {
				//4. Modifica datele personale
				interfataClient->afiseazaMeniuEditare();
				cin >> client;

				cout << "\Datale tale au fost modificate cu succes!\n";

				cout << "\n0. Inapoi\n";
				int back;
				while (cin >> back) {
					if (back != 0)
						cout << "Daca nu introduci valoarea 0 nu te vei mai putea intoarce niciodata! * ^ *\n";
					else
						break;
				}
			}
			else if (optiune == 5) {
				//5. Trimite comanda
				// se instantiaza clasa comanda si se adauga cosul, cantitatile, nr de produse si datele clientului
				// se scrie intr-un fisier comanda
			}
			else if (optiune == 6) {
				//6. Vizualizeaza raportul ultimei comenzi trimise
				// se citeste din fisier comanda trimisa
			}
			else if (optiune == 0) {
				break;
			}
		}

	}
	else {
		while (1) {
			int optiune;
			interfataMagazin->afiseazaMeniu();
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
					interfataMagazin->afiseazaMeniuAdauga();
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
					else if (optiuneAdauga == 4) {
						produs = new Laptop;
					}
					else {
						break;
					}

					produs->editareProdus();
					magazin += produs;
					cout << "Produsul a fost adaugat cu succes!\n";
				}
			}
			else if (optiune == 2) {
				//2. Editare Produse magazin
				//operator []
				interfataMagazin->afiseazaMeniuEditare();
				magazin.vizualizareProduse();
				cout << "\nIntrodu numarul produsului pe care doresti sa-l editezi: ";
				int nrProdus;
				while (cin >> nrProdus) {
					if (nrProdus < 1 || nrProdus > magazin.getNrProduse())
						cout << "Valoarea introdusa nu face parte din lista!\n";
					else
						break;
				}

				//decrementez pentru a potrivi val introdusa cu indexul produsului
				nrProdus--;
				magazin[nrProdus]->editareProdus();
				magazin.writeFileProduseMagazin();
			}
			else if (optiune == 3) {
				//3. Sterge produse magazin
				interfataMagazin->afiseazaMeniuSterge();
				magazin.vizualizareProduse();
				cout << "\nIntrodu numarul produsului pe care doresti sa-l stergi: ";
				int nrProdus;
				while (cin >> nrProdus) {
					if (nrProdus < 1 || nrProdus > magazin.getNrProduse())
						cout << "Valoarea introdusa nu face parte din lista!\n";
					else
						break;
				}

				nrProdus--;
				magazin -= nrProdus;

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