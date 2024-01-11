#include <iostream>
#include "Produs.h"
#include "Client.h"
#include "Magazin.h"
#include "Subler.h"
#include "MasinaDeTunsIarba.h"
#include "Bormasina.h"
#include "Laptop.h"
#include "CombinaFrigorifica.h"
#include "Comanda.h"
#include <queue>
#include <list>

using namespace std;

int main() {
	string tipUser;

	Magazin magazin("MAMOV", 0, nullptr);
	magazin.readFileProduseMagazin();

	IMagazin* interfataMagazin = &magazin;
	
	Client client("Ovidiu", "0752925119", 18, 0, nullptr, nullptr);
	IMagazin* interfataClient = &client;
	client.recupereazaCos();

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
				if (magazin.getNrProduse() == 0) {
					cout << "\nNu exista produse in magazin!\n ";
				}
				else {
					magazin.vizualizareProduse();
					cout << "\nIntrodu o valoare: ";
					int nrProdus;
					while (cin >> nrProdus) {
						if (nrProdus < 1 || nrProdus > magazin.getNrProduse())
							cout << "Optiune invalida! Te rugam sa introduci alta valoare!\n";
						else
							break;
					}

					int cantitate;
					cout << "Introdu cantitatea dorita: ";
					while (cin >> cantitate) {
						if (cantitate < 1 || cantitate > magazin[nrProdus - 1]->getCantitate())
							cout << "Cantitatea introdusa este invalida! Incearca din nou!\n";
						else
							break;
					}

					if (cantitate <= 0) {
						cout << "Cantitatea trebuie sa fie mai mare decat zero.\n";
					}
					else {
						client.adaugaProdusInCos(magazin[nrProdus - 1], cantitate);
						cout << "\nProdusul a fost adaugat in cos cu succes!\n";
					}
				}
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
				if (client.getNrProduseCos() == 0)
					cout << "\Cosul este gol!\n";
				else {
					client.afisareCos();
					int nrProdus;
					cout << "\nIntrodu numarul produsului pe care doresti sa-l scoti: ";
					while (cin >> nrProdus) {
						if (nrProdus < 1 || nrProdus > client.getNrProduseCos())
							cout << "Optiune invalida!Te rugam sa introduci alta valoare!\n";
						else
							break;
					}

					client.scoateProdusDinCos(nrProdus - 1);
					cout << "\nProdusul a fost scos din cos cu succes!\n";
				}
				
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
				if (client.getNrProduseCos() == 0) {
					cout << "\nCosul tau este gol! Comanda nu poate fi trimisa!\n";
				}
				else {
					Comanda comanda(to_string(rand()), client.getNume(), client.getTelefon(), client.getNrProduseCos(), client.getCantitati(), client.getProduseCosClient());
					comanda.writeFileComanda();
					client.resetCos();
					system("CLS");
					cout << "\nComanda a fost trimisa cu scucces!\n";

					cout << "\n0. Inapoi\n";
					int back;
					while (cin >> back) {
						if (back != 0)
							cout << "Daca nu introduci valoarea 0 nu te vei mai putea intoarce niciodata! * ^ *\n";
						else
							break;
					}
				}
				
			}
			else if (optiune == 6) {
				//6. Vizualizeaza raportul ultimei comenzi trimise
				client.afiseazaMeniuUltimaComanda();
				ifstream fin;
				fin.open("Comenzi.dat", ios::in);

				Comanda comanda;

				bool isEmpty = fin.peek() == EOF;
				if (!isEmpty) {
					while (fin.peek() != EOF) {
						comanda.readFileComanda(fin);
					}
					
					fin.close();
					cout << comanda;
				}
				else {
					cout << "\nNu exista nicio comanda!\n";
				}

				cout << "\n0. Inapoi\n";
				int back;
				while (cin >> back) {
					if (back != 0)
						cout << "Daca nu introduci valoarea 0 nu te vei mai putea intoarce niciodata! * ^ *\n";
					else
						break;
				}
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
					else if (optiuneAdauga == 5) {
						produs = new CombinaFrigorifica;
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
				if (magazin.getNrProduse() == 0) {
					cout << "\nNu exista produse in magazin!\n ";
				}
				else {
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

					cout << "Produsul a fost editat cu succes!\n";
				}

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
				//3. Sterge produse magazin
				interfataMagazin->afiseazaMeniuSterge();
				if (magazin.getNrProduse() == 0) {
					cout << "\nNu exista produse in magazin!\n ";
				}
				else {
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

					cout << "Produsul a fost sters cu succes!\n";
				}

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
				//4. Prelucrare comenzi
				// se afiseaza comenzile primite
				queue<Comanda, list<Comanda>> coadaComenzi;
				ifstream fin;
				fin.open("Comenzi.dat", ios::in);

				bool isEmpty = fin.peek() == EOF;
				if (!isEmpty) {
					while (fin.peek() != EOF) {
						Comanda comanda;
						comanda.readFileComanda(fin);

						coadaComenzi.push(comanda);
					}
				}

				fin.close();

				while (!coadaComenzi.empty()) {
					cout << "Comanda cu id-ul " << coadaComenzi.front().getId() << " a fost ambalata cu success si trimisa spre curier!\n";

					Produs** aux = new Produs * [coadaComenzi.front().getNrProduseComanda()];
					aux = coadaComenzi.front().getProduseComandaClient();
					vector<int> cantitati = coadaComenzi.front().getCantitati();

					for (int i = 0; i < coadaComenzi.front().getNrProduseComanda(); i++) {
						magazin.scadeCantitateById(aux[i]->getId(), cantitati[i]);
					}

					delete[] aux;

					coadaComenzi.pop();
				}

				ofstream fout;
				fout.open("Comenzi.dat", ios::out | ios::trunc);
				fout.close();

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