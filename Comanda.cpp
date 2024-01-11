#include "Comanda.h"

Comanda::Comanda()
{
	comanda_id = to_string(rand());
	cantitati.resize(0);
	nrProduseComanda = 0;
	produseComandaClient = nullptr;
	valoarea_totala = 0;
	nume_client = "Ovidiu";
	telefon_client = "0752925119";
}

Comanda::Comanda(string comanda_id, string nume_client, string telefon_client, int nrProduseComanda, vector<int> cantitati, Produs** produseComandaClient)
{
	this->comanda_id = comanda_id;
    valoarea_totala = 0;
	this->nume_client = nume_client;
	this->telefon_client = telefon_client;
	this->nrProduseComanda = nrProduseComanda;
    if (nrProduseComanda != 0) {
        this->cantitati.clear();
        this->produseComandaClient = new Produs * [nrProduseComanda];
        for (int i = 0; i < nrProduseComanda; i++) {
            this->cantitati.push_back(cantitati[i]);
            this->produseComandaClient[i] = produseComandaClient[i];
            valoarea_totala += cantitati[i] * produseComandaClient[i]->getPret();
        }
    }
    else {
        this->cantitati.resize(0);
        this->produseComandaClient = nullptr;
    }

}

Comanda::~Comanda()
{
    cantitati.clear();
}

int Comanda::getNrProduseComanda()
{
	return nrProduseComanda;
}

Produs** Comanda::getProduseComandaClient()
{
	return produseComandaClient;
}

string Comanda::getId()
{
	return comanda_id;
}

vector<int> Comanda::getCantitati()
{
	return cantitati;
}

void Comanda::serialize(ofstream& fout) const
{
	//asa scriu elementele de tip int, float etc, elem numerice
	fout.write((char*)&nrProduseComanda, sizeof(nrProduseComanda));
	fout.write((char*)&valoarea_totala, sizeof(valoarea_totala));
	for (int i = 0; i < nrProduseComanda; i++)
		fout.write((char*)&cantitati[i], sizeof(cantitati[i]));
	
	// asa scriu elementele de tip string
	//le scriu marimea
	int comanda_idSize = comanda_id.size();
	fout.write((char*)&comanda_idSize, sizeof(comanda_idSize));
	fout.write(comanda_id.c_str(), comanda_idSize);

	int nume_clientSize = nume_client.size();
	fout.write((char*)&nume_clientSize, sizeof(nume_clientSize));
	fout.write(nume_client.c_str(), nume_clientSize);

	int telefon_clientSize = telefon_client.size();
	fout.write((char*)&telefon_clientSize, sizeof(telefon_clientSize));
	fout.write(telefon_client.c_str(), telefon_clientSize);
}

void Comanda::deserialize(ifstream& fin)
{
	fin.read((char*)&nrProduseComanda, sizeof(nrProduseComanda));
	fin.read((char*)&valoarea_totala, sizeof(valoarea_totala));
	cantitati.resize(nrProduseComanda);
	for (int i = 0; i < nrProduseComanda; i++)
		fin.read((char*)&cantitati[i], sizeof(cantitati[i]));

	int comanda_idSize;
	fin.read((char*)&comanda_idSize, sizeof(comanda_idSize));
	char buffer[100];
	fin.read(buffer, comanda_idSize);
	buffer[comanda_idSize] = '\0';
	comanda_id = buffer;

	int nume_clientSize;
	fin.read((char*)&nume_clientSize, sizeof(nume_clientSize));
	fin.read(buffer, nume_clientSize);
	buffer[nume_clientSize] = '\0';
	nume_client = buffer;

	int telefon_clientSize;
	fin.read((char*)&telefon_clientSize, sizeof(telefon_clientSize));
	fin.read(buffer, telefon_clientSize);
	buffer[telefon_clientSize] = '\0';
	telefon_client = buffer;
}

void Comanda::writeFileComanda()
{
	ofstream fout;
	fout.open("Comenzi.dat", ios::out | ios::app);
	this->serialize(fout);
	for (int i = 0; i < this->nrProduseComanda; i++) 
	{
		int tip;
		string numeProdus = produseComandaClient[i]->getNume();
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
		produseComandaClient[i]->serialize(fout);
	}
	fout.close();
}

void Comanda::readFileComanda(ifstream& fin)
{
	this->deserialize(fin);

	Produs** aux = new Produs * [nrProduseComanda];

	for (int i = 0; i < nrProduseComanda; i++) {
		
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

	produseComandaClient = aux;
}

void Comanda::adaugaProdus(Produs* produs) {
	Produs** aux = new Produs * [nrProduseComanda + 1];
	for (int i = 0; i < nrProduseComanda; i++) {
		aux[i] = produseComandaClient[i];
	}
	aux[nrProduseComanda] = produs;
	nrProduseComanda++;
	delete[] produseComandaClient;
	produseComandaClient = aux;
}

ostream& operator<<(ostream& cout, const Comanda& comanda)
{
	cout << "Comanda cu id-ul " << comanda.comanda_id << ", in valoare de " << comanda.valoarea_totala << " lei, contine urmatoarele produse:\n";
	for (int i = 0; i < comanda.nrProduseComanda; i++) {
		cout << i + 1 << ". " << comanda.produseComandaClient[i]->getNume() << " " << comanda.produseComandaClient[i]->getMarca() << " x " << comanda.cantitati[i] << " buc.\n";
	}

	return cout;
}
