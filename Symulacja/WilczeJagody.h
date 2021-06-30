#pragma once
#include "Roslina.h"

#define SILA_WILCZE_JAGODY 99
#define SYMBOL_WILCZE_JAGODY '+'

class WilczeJagody : public Roslina {
public:
	WilczeJagody(Swiat* swiat, Punkt& polozenie);

	void Rysowanie() override;
	bool CzyTrujacy() override;
	Organizm* WygenerujKopie(Punkt polozenie) override;

	~WilczeJagody();
};