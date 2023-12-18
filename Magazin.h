#pragma once
#include "Produs.h"
#include <iostream>

using namespace std;
class Magazin
{
protected:
	string nume;

public:
	Magazin();
	Magazin(string nume);

	string getNume();
};

