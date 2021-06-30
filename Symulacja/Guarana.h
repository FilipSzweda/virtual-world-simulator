#pragma once
#include "Roslina.h"

#define SILA_GUARANA 0
#define SYMBOL_GUARANA '$'

class Guarana : public Roslina {
public:
	Guarana(Swiat* swiat, Punkt& polozenie);

	void Rysowanie() override;
	bool CzyBonusSily() override;
	Organizm* WygenerujKopie(Punkt polozenie) override;

	~Guarana();
};