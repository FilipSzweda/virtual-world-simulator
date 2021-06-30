#pragma once
#include "Zwierze.h"

#define SILA_CZLOWIEK 5
#define INICJATYWA_CZLOWIEK 4
#define SYMBOL_CZLOWIEK 'C'

#define STRZALKA_GORA 72
#define STRZALKA_PRAWO 77
#define STRZALKA_DOL 80
#define STRZALKA_LEWO 75
#define SPACJA 32
#define ENTER 13

class Czlowiek : public Zwierze {
public:
	Czlowiek(Swiat* swiat, Punkt& polozenie);
	Czlowiek(Swiat* swiat, Punkt& polozenie, int sila);

	void Akcja() override;
	bool CzyTarczaAlzura() override;
	void Rysowanie() override;
	Organizm* WygenerujKopie(Punkt polozenie) override;

	~Czlowiek();
};