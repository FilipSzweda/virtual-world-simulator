#include "Trawa.h"

Trawa::Trawa(Swiat* swiat, Punkt& polozenie)
	: Roslina(swiat, polozenie, SYMBOL_TRAWA, SILA_TRAWA) {
	printf("Nowa Trawa w polozeniu (%i, %i)\n", this->GetPolozenie().GetX(), this->GetPolozenie().GetY());
}

void Trawa::Rysowanie() {
	printf("\033[92m%c\033[0m ", this->GetSymbol());
}

Organizm* Trawa::WygenerujKopie(Punkt polozenie) {
	Organizm* dziecko = new Trawa(this->GetSwiat(), polozenie);
	return dziecko;
}

Trawa::~Trawa() {
	printf("Zjedzenie trawy w polozeniu (%i, %i)\n", this->GetPolozenie().GetX(), this->GetPolozenie().GetY());
}