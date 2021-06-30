#pragma once
#include "Roslina.h"

#define SILA_BARSZCZ_SOSNOWSKIEGO 10
#define SYMBOL_BARSZCZ_SOSNOWSKIEGO 'x'

class BarszczSosnowskiego : public Roslina {
public:
	BarszczSosnowskiego(Swiat* swiat, Punkt& polozenie);

	void Akcja() override;
	void Rysowanie() override;
	bool CzyTrujacy() override;
	Organizm* WygenerujKopie(Punkt polozenie) override;

	~BarszczSosnowskiego();
};