#pragma once
#include "Roslina.h"

#define SILA_MLECZ 0
#define SYMBOL_MLECZ '*'
#define PROBY_ZASIEWU_MLECZ 3

class Mlecz : public Roslina {
public:
	Mlecz(Swiat* swiat, Punkt& polozenie);

	void Akcja() override;
	void Rysowanie() override;
	Organizm* WygenerujKopie(Punkt polozenie) override;

	~Mlecz();
};