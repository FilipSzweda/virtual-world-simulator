#include "Zolw.h"

Zolw::Zolw(Swiat* swiat, Punkt& polozenie)
	: Zwierze(swiat, polozenie, SYMBOL_ZOLW, SILA_ZOLW, INICJATYWA_ZOLW) {
	printf("Nowy Zolw w polozeniu (%i, %i)\n", this->GetPolozenie().GetX(), this->GetPolozenie().GetY());
}

Zolw::Zolw(Swiat* swiat, Punkt& polozenie, int sila)
	: Zwierze(swiat, polozenie, SYMBOL_ZOLW, sila, INICJATYWA_ZOLW) {
	printf("Nowy Zolw w polozeniu (%i, %i)\n", this->GetPolozenie().GetX(), this->GetPolozenie().GetY());
}

void Zolw::Akcja() {
	int szansaNaRuch = rand() % 4;
	if (szansaNaRuch == 0) {
		if (this->ZnajdzPolozeniaObok().size() > 0) {
			int indexWylosowanegoPolozenia = rand() % this->ZnajdzPolozeniaObok().size();
			this->SetPolozenie(this->ZnajdzPolozeniaObok()[indexWylosowanegoPolozenia]);
		}
	}
}

void Zolw::Rysowanie() {
	printf("%c ", this->GetSymbol());
}

bool Zolw::CzyOdbilAtak(Organizm* organizmAtakujacy) {
	if (organizmAtakujacy->GetSila() < 5) {
		return true;
	}
	else {
		return false;
	}
}

Organizm* Zolw::WygenerujKopie(Punkt polozenie) {
	Organizm* dziecko = new Zolw(this->GetSwiat(), polozenie);
	return dziecko;
}

Zolw::~Zolw() {
	printf("Smierc Zolwia w polozeniu (%i, %i)\n", this->GetPolozenie().GetX(), this->GetPolozenie().GetY());
}