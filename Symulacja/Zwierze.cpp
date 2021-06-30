#include "Zwierze.h"

Zwierze::Zwierze(Swiat* swiat, Punkt polozenie, char symbol, int sila, int inicjatywa)
	: Organizm(swiat, polozenie, symbol, sila, inicjatywa) {
}

bool Zwierze::CzyZwierze() {
	return true;
}

void Zwierze::Akcja() {
	if (this->ZnajdzPolozeniaObok().size() > 0) {
		int indeksWylosowanegoPolozenia = rand() % this->ZnajdzPolozeniaObok().size();
		this->SetPolozenie(this->ZnajdzPolozeniaObok()[indeksWylosowanegoPolozenia]);
	}
}

void Zwierze::Kolizja(Organizm* organizmKolidujacy, Punkt polozeniePoczatkowe) {
	if (this->GetSymbol() == organizmKolidujacy->GetSymbol()) {
		this->Rozmnazanie(organizmKolidujacy, polozeniePoczatkowe);
	}
	else {
		this->Walka(organizmKolidujacy, polozeniePoczatkowe);
	}
}

Zwierze::~Zwierze() {
}