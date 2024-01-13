#include "MasinaDeTunsIarba.h"

MasinaDeTunsIarba::MasinaDeTunsIarba()
{
	nume = "Masina de tuns iarba";
	serie = "xc230";
	culoare = "albastru";
	marimeRezervor = 4.2;
}

MasinaDeTunsIarba::MasinaDeTunsIarba(int idProdus, int cantitate, float pret, float rating, string nume, string marca, string desciere, string serie, string culoare, float marimeRezervor) : Produs(idProdus, cantitate, pret, rating, nume, marca, desciere)
{
	this->serie = serie;
	this->culoare = culoare;
	if (marimeRezervor > 0)
		this->marimeRezervor = marimeRezervor;
}

void MasinaDeTunsIarba::setSerie(string serie)
{
	this->serie = serie;
}

string MasinaDeTunsIarba::getSerie()
{
	return serie;
}

void MasinaDeTunsIarba::setCuloare(string culoare)
{
	this->culoare = culoare;
}

string MasinaDeTunsIarba::getCuloare()
{
	return culoare;
}

string MasinaDeTunsIarba::getNume()
{
	return nume;
}

void MasinaDeTunsIarba::setMarimeRezervor(int marimeRezervor)
{
	if (marimeRezervor > 0)
		this->marimeRezervor = marimeRezervor;
}

int MasinaDeTunsIarba::getMarimeRezervor()
{
	return marimeRezervor;
}

void MasinaDeTunsIarba::afisareDetalii()
{
	cout << "Masina de tuns iarba " << nume << "este de serie " << serie << ", are culoarea " << culoare << " si are o capacitate a rezervorului de " << marimeRezervor << " litri. Are pretul de " << pret << "lei si are un rating de " << rating << "/ 5 stele. Cantitatea disponibila este de " << cantitate << " bucati!\n" << descriere << "\n";
}

  void MasinaDeTunsIarba::editareProdus() {
	this->Produs::editareProdus();
	cout << "Serie: ";
	getline(cin, serie);
	cout << "Culoare: ";
	getline(cin, culoare);
	cout << "Marime rezervor: ";
	while (cin >> marimeRezervor) {
		if (marimeRezervor <= 0)
			cout << "Valoare invalida! Introdu alta valoare: ";
		else
			break;
	}
}

  void MasinaDeTunsIarba::serialize(ofstream& fout) const
  {
	  Produs::serialize(fout);
	  fout.write((char*)&marimeRezervor, sizeof(marimeRezervor));

	  int serieSize = serie.size();
	  fout.write((char*)&serieSize, sizeof(serieSize));
	  fout.write(serie.c_str(), serieSize);

	  int culoareSize = culoare.size();
	  fout.write((char*)&culoareSize, sizeof(culoareSize));
	  fout.write(culoare.c_str(), culoareSize);
  }

  void MasinaDeTunsIarba::deserialize(ifstream& fin)
  {
	  Produs::deserialize(fin);
	  fin.read((char*)&marimeRezervor, sizeof(marimeRezervor));

	  int serieSize;
	  fin.read((char*)&serieSize, sizeof(serieSize));
	  char buffer[200];
	  fin.read(buffer, serieSize);
	  buffer[serieSize] = '\0';
	  serie = buffer;

	  int culoareSize;
	  fin.read((char*)&culoareSize, sizeof(culoareSize));
	  fin.read(buffer, culoareSize);
	  buffer[culoareSize] = '\0';
	  culoare = buffer;
  }

  ofstream& operator<<(ofstream& out, MasinaDeTunsIarba& m) {
	  out << m.nume;
	  out << m.serie;
	  out << m.culoare;
	  out << m.marimeRezervor;
	  out << m.pret;
	  out << m.rating;
	  out << m.cantitate;
	  out << m.descriere;

	  return out;
  }