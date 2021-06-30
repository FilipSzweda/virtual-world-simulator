#pragma once
#include "Roslina.h"

#define SILA_TRAWA 0
#define SYMBOL_TRAWA '#'

class Trawa : public Roslina {
public:
	Trawa(Swiat* swiat, Punkt& polozenie);

	void Rysowanie() override;
	Organizm* WygenerujKopie(Punkt polozenie) override;

	~Trawa();
};