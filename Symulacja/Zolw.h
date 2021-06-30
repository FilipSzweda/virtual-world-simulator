#pragma once
#include "Zwierze.h"

#define SILA_ZOLW 2
#define INICJATYWA_ZOLW 1
#define SYMBOL_ZOLW 'Z'

class Zolw : public Zwierze {
public:
	Zolw(Swiat* swiat, Punkt& polozenie);
	Zolw(Swiat* swiat, Punkt& polozenie, int sila);

	void Akcja() override;
	void Rysowanie() override;
	bool CzyOdbilAtak(Organizm* organizmAtakujacy) override;
	Organizm* WygenerujKopie(Punkt polozenie) override;

	~Zolw();
};