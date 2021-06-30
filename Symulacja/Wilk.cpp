#include "Wilk.h"

Wilk::Wilk(Swiat* swiat, Punkt& polozenie)
	: Zwierze(swiat, polozenie, SYMBOL_WILK, SILA_WILK, INICJATYWA_WILK) {
	printf("Nowy Wilk w polozeniu (%i, %i)\n", this->GetPolozenie().GetX(), this->GetPolozenie().GetY());
}

Wilk::Wilk(Swiat* swiat, Punkt& polozenie, int sila)
	: Zwierze(swiat, polozenie, SYMBOL_WILK, sila, INICJATYWA_WILK) {
	printf("Nowy Wilk w polozeniu (%i, %i)\n", this->GetPolozenie().GetX(), this->GetPolozenie().GetY());
}

void Wilk::Rysowanie() {
	printf("%c ", this->GetSymbol());
}

Organizm* Wilk::WygenerujKopie(Punkt polozenie) {
	Organizm* dziecko = new Wilk(this->GetSwiat(), polozenie);
	return dziecko;
}

Wilk::~Wilk() {
	printf("Smierc Wilka w polozeniu (%i, %i)\n", this->GetPolozenie().GetX(), this->GetPolozenie().GetY());
}