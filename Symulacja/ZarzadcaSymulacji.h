#pragma once
#include "Swiat.h"
#include "Organizm.h"
#include "Zwierze.h"
#include "Antylopa.h"
#include "Lis.h"
#include "Owca.h"
#include "Wilk.h"
#include "Zolw.h"
#include "Czlowiek.h"
#include "Roslina.h"
#include "BarszczSosnowskiego.h"
#include "Guarana.h"
#include "Mlecz.h"
#include "Trawa.h"
#include "WilczeJagody.h"

class ZarzadcaSymulacji {
private:
	Swiat* swiat;
public:
	ZarzadcaSymulacji(Swiat* swiat);

	void NowaSymulacja();
	void WczytajSymulacje();
	void Symuluj();

	~ZarzadcaSymulacji();
};
