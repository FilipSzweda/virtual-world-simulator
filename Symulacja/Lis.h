#pragma once
#include "Zwierze.h"

#define SILA_LIS 3
#define INICJATYWA_LIS 7
#define SYMBOL_LIS 'L'

class Lis : public Zwierze {
public:
	Lis(Swiat* swiat, Punkt& polozenie);
	Lis(Swiat* swiat, Punkt& polozenie, int sila);

	void Akcja() override;
	void Rysowanie() override;
	Organizm* WygenerujKopie(Punkt polozenie) override;

	~Lis();
};