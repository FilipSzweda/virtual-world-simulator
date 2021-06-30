#include "WilczeJagody.h"

WilczeJagody::WilczeJagody(Swiat* swiat, Punkt& polozenie)
	: Roslina(swiat, polozenie, SYMBOL_WILCZE_JAGODY, SILA_WILCZE_JAGODY) {
	printf("Nowe Wilcze Jagody w polozeniu (%i, %i)\n", this->GetPolozenie().GetX(), this->GetPolozenie().GetY());
}

void WilczeJagody::Rysowanie() {
	printf("\033[91m%c\033[0m ", this->GetSymbol());
}

bool WilczeJagody::CzyTrujacy() {
	return true;
}

Organizm* WilczeJagody::WygenerujKopie(Punkt polozenie) {
	Organizm* dziecko = new WilczeJagody(this->GetSwiat(), polozenie);
	return dziecko;
}

WilczeJagody::~WilczeJagody() {
	printf("Zjedzenie Wilczych Jagod w polozeniu (%i, %i)\n", this->GetPolozenie().GetX(), this->GetPolozenie().GetY());
}