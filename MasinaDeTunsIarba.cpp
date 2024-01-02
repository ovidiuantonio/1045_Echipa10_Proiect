#include "MasinaDeTunsIarba.h"

MasinaDeTunsIarba::MasinaDeTunsIarba()
{
	serie = "xc230";
	culoare = "albastru";
	marimeRezervor = 4.2;
}

MasinaDeTunsIarba::MasinaDeTunsIarba(int cantitate, float pret, float rating, string nume, string marca, string desciere, string serie, string culoare, float marimeRezervor) : Produs(cantitate, pret, rating, nume, marca, desciere)
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
	Produs::editareProdus();
	cin >> serie;
	cin >> culoare;
	cin >> marimeRezervor;
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