#pragma once
#include "Zwierze.h"

#define SILA_OWCA 4
#define INICJATYWA_OWCA 4
#define SYMBOL_OWCA 'O'

class Owca : public Zwierze {
public:
	Owca(Swiat* swiat, Punkt& polozenie);
	Owca(Swiat* swiat, Punkt& polozenie, int sila);

	void Rysowanie() override;
	Organizm* WygenerujKopie(Punkt polozenie) override;

	~Owca();
};