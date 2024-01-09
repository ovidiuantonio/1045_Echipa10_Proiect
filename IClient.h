#pragma once
class IClient
{
public: 
	virtual void afisareCos() = 0;
	virtual void afiseazaMeniu() = 0;
	virtual void afiseazaMeniuAdauga() = 0;
	virtual void afiseazaMeniuSterge() = 0;
	virtual void afiseazaMeniuEditare() = 0;
	virtual void afiseazaMeniuProduseMagazin() = 0;
};

