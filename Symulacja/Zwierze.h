#pragma once
#include "Organizm.h"
#include "Swiat.h"

class Zwierze : public Organizm {
public:
	Zwierze(Swiat* swiat, Punkt polozenie, char symbol, int sila, int inicjatywa);

	bool CzyZwierze() override;
	void Akcja() override;
	void Kolizja(Organizm* organizmKolidujacy, Punkt polozeniePoczatkowe) override;

	virtual ~Zwierze();
};
