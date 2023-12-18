#include "Magazin.h"


Magazin::Magazin() {
	nume = "Default";

}

Magazin::Magazin(string nume)
{
	this->nume = nume;
}

string Magazin::getNume()
{
	return nume;
}
