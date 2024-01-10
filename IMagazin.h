#pragma once
class IMagazin
{
public:
	virtual void afiseazaMeniu() = 0;
	virtual void afiseazaMeniuAdauga() = 0;
	virtual void afiseazaMeniuEditare() = 0;
	virtual void afiseazaMeniuSterge() = 0;
	virtual void afiseazaMeniuProduseMagazin() = 0;
};

