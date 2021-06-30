#include "Guarana.h"

Guarana::Guarana(Swiat* swiat, Punkt& polozenie)
	: Roslina(swiat, polozenie, SYMBOL_GUARANA, SILA_GUARANA) {
	printf("Nowa Guarana w polozeniu (%i, %i)\n", this->GetPolozenie().GetX(), this->GetPolozenie().GetY());
}

void Guarana::Rysowanie() {
	printf("\033[94m%c\033[0m ", this->GetSymbol());
}

bool Guarana::CzyBonusSily() {
	return true;
}

Organizm* Guarana::WygenerujKopie(Punkt polozenie) {
	Organizm* dziecko = new Guarana(this->GetSwiat(), polozenie);
	return dziecko;
}

Guarana::~Guarana() {
	printf("Zjedzenie Guarany w polozeniu (%i, %i)\n", this->GetPolozenie().GetX(), this->GetPolozenie().GetY());
}