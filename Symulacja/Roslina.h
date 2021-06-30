#pragma once
#include "Organizm.h"
#include "Swiat.h"

#define INICJATYWA_ROSLINA 0

class Roslina : public Organizm {
public:
	Roslina(Swiat* swiat, Punkt polozenie, char symbol, int sila);

	void Akcja() override;
	void Kolizja(Organizm* organizmKoliduj¹cy, Punkt polozeniePoczatkowe) override;

	virtual ~Roslina();
};