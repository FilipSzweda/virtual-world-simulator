#include "Owca.h"

Owca::Owca(Swiat* swiat, Punkt& polozenie)
	: Zwierze(swiat, polozenie, SYMBOL_OWCA, SILA_OWCA, INICJATYWA_OWCA) {
	printf("Nowa Owca w polozeniu (%i, %i)\n", this->GetPolozenie().GetX(), this->GetPolozenie().GetY());
}

Owca::Owca(Swiat* swiat, Punkt& polozenie, int sila)
	: Zwierze(swiat, polozenie, SYMBOL_OWCA, sila, INICJATYWA_OWCA) {
	printf("Nowa Owca w polozeniu (%i, %i)\n", this->GetPolozenie().GetX(), this->GetPolozenie().GetY());
}

void Owca::Rysowanie() {
	printf("%c ", this->GetSymbol());
}

Organizm* Owca::WygenerujKopie(Punkt polozenie) {
	Organizm* dziecko = new Owca(this->GetSwiat(), polozenie);
	return dziecko;
}

Owca::~Owca() {
	printf("Smierc Owcy w polozeniu (%i, %i)\n", this->GetPolozenie().GetX(), this->GetPolozenie().GetY());
}