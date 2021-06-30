#include "Lis.h"

Lis::Lis(Swiat* swiat, Punkt& polozenie)
	: Zwierze(swiat, polozenie, SYMBOL_LIS, SILA_LIS, INICJATYWA_LIS) {
	printf("Nowy Lis w polozeniu (%i, %i)\n", this->GetPolozenie().GetX(), this->GetPolozenie().GetY());
}

Lis::Lis(Swiat* swiat, Punkt& polozenie, int sila)
	: Zwierze(swiat, polozenie, SYMBOL_LIS, sila, INICJATYWA_LIS) {
	printf("Nowy Lis w polozeniu (%i, %i)\n", this->GetPolozenie().GetX(), this->GetPolozenie().GetY());
}

void Lis::Akcja() {
	std::vector <Punkt> nieSilniejszePolozenia;
	for (int i = 0; i < this->ZnajdzPolozeniaObok().size(); i++) {
		if (this->GetSwiat()->GetMapa()[this->ObliczIndexNaMapie(this->ZnajdzPolozeniaObok()[i])] != nullptr) {
			if (this->GetSwiat()->GetMapa()[this->ObliczIndexNaMapie(this->ZnajdzPolozeniaObok()[i])]->GetSila() <= this->GetSila()) {
				nieSilniejszePolozenia.push_back(this->ZnajdzPolozeniaObok()[i]);
			}
		}
		else {
			nieSilniejszePolozenia.push_back(this->ZnajdzPolozeniaObok()[i]);
		}
	}
	if (nieSilniejszePolozenia.size() > 0) {
		int indexWylosowanegoPolozenia = rand() % nieSilniejszePolozenia.size();
		this->SetPolozenie(nieSilniejszePolozenia[indexWylosowanegoPolozenia]);
	}
}


void Lis::Rysowanie() {
	printf("%c ", this->GetSymbol());
}

Organizm* Lis::WygenerujKopie(Punkt polozenie) {
	Organizm* dziecko = new Lis(this->GetSwiat(), polozenie);
	return dziecko;
}

Lis::~Lis() {
	printf("Smierc Lisa w polozeniu (%i, %i)\n", this->GetPolozenie().GetX(), this->GetPolozenie().GetY());
}