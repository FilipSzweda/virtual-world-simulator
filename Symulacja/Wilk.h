#pragma once
#include "Zwierze.h"

#define SILA_WILK 9
#define INICJATYWA_WILK 5
#define SYMBOL_WILK 'W'

class Wilk : public Zwierze {
public:
	Wilk(Swiat* swiat, Punkt& polozenie);
	Wilk(Swiat* swiat, Punkt& polozenie, int sila);

	void Rysowanie() override;
	Organizm* WygenerujKopie(Punkt polozenie) override;

	~Wilk();
};