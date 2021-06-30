#pragma once
#include "Zwierze.h"

#define SILA_ANTYLOPA 4
#define INICJATYWA_ANTYLOPA 4
#define SYMBOL_ANTYLOPA 'A'

class Antylopa : public Zwierze {
public:
	Antylopa(Swiat* swiat, Punkt& polozenie);
	Antylopa(Swiat* swiat, Punkt& polozenie, int sila);

	void Akcja() override;
	void Rysowanie() override;
	bool CzyUcieklPrzedWalka() override;
	Organizm* WygenerujKopie(Punkt polozenie) override;

	~Antylopa();
};