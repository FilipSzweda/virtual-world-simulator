#include "Mlecz.h"

Mlecz::Mlecz(Swiat* swiat, Punkt& polozenie)
	: Roslina(swiat, polozenie, SYMBOL_MLECZ, SILA_MLECZ) {
	printf("Nowy Mlecz w polozeniu (%i, %i)\n", this->GetPolozenie().GetX(), this->GetPolozenie().GetY());
}

void Mlecz::Akcja() {
	bool polozenieDlaRoslinyZnalezione = false;
	for (int i = 0; i < PROBY_ZASIEWU_MLECZ; i++) {
		int zasiew = rand() % (int)(1 / this->GetSwiat()->GetPrawdopodobienstwoZasiewu());
		if (zasiew == 0) {
			std::vector <Punkt> polozeniaDlaRosliny;
			for (int i = 0; i < this->ZnajdzPolozeniaObok().size(); i++) {
				if (this->GetSwiat()->GetMapa()[this->ObliczIndexNaMapie(this->ZnajdzPolozeniaObok()[i])] == nullptr) {
					polozeniaDlaRosliny.push_back(this->ZnajdzPolozeniaObok()[i]);
					polozenieDlaRoslinyZnalezione = true;
				}
			}
			if (polozeniaDlaRosliny.size() > 0) {
				int indexWylosowanegoPolozenia = rand() % polozeniaDlaRosliny.size();
				this->GetSwiat()->DodajOrganizm(this->WygenerujKopie(polozeniaDlaRosliny[indexWylosowanegoPolozenia]));
			}
		}
		if (polozenieDlaRoslinyZnalezione == true) {
			break;
		}
	}
}

void Mlecz::Rysowanie() {
	printf("\033[93m%c\033[0m ", this->GetSymbol());
}

Organizm* Mlecz::WygenerujKopie(Punkt polozenie) {
	Organizm* dziecko = new Mlecz(this->GetSwiat(), polozenie);
	return dziecko;
}

Mlecz::~Mlecz() {
	printf("Zjedzenie Mlecza w polozeniu (%i, %i)\n", this->GetPolozenie().GetX(), this->GetPolozenie().GetY());
}