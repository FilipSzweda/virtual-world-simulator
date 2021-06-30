#include "BarszczSosnowskiego.h"

BarszczSosnowskiego::BarszczSosnowskiego(Swiat* swiat, Punkt& polozenie)
	: Roslina(swiat, polozenie, SYMBOL_BARSZCZ_SOSNOWSKIEGO, SILA_BARSZCZ_SOSNOWSKIEGO) {
	printf("Nowy Barszcz Sosnowskiego w polozeniu (%i, %i)\n", this->GetPolozenie().GetX(), this->GetPolozenie().GetY());
}

void BarszczSosnowskiego::Akcja() {
	std::vector <Organizm*> zatruteZwierzeta;
	for (int i = 0; i < this->ZnajdzPolozeniaObok().size(); i++) {
		if (this->GetSwiat()->GetMapa()[this->ObliczIndexNaMapie(this->ZnajdzPolozeniaObok()[i])] != nullptr) {
			if (this->GetSwiat()->GetMapa()[this->ObliczIndexNaMapie(this->ZnajdzPolozeniaObok()[i])]->CzyZwierze() == true) {
				zatruteZwierzeta.push_back(this->GetSwiat()->GetMapa()[this->ObliczIndexNaMapie(this->ZnajdzPolozeniaObok()[i])]);
			}
		}
	}
	for (int i = 0; i < zatruteZwierzeta.size(); i++) {
		zatruteZwierzeta[i]->UsunOrganizmZMapy(zatruteZwierzeta[i]->GetPolozenie());
		zatruteZwierzeta[i]->SetZywy(false);	
	}
	this->Roslina::Akcja();
}

void BarszczSosnowskiego::Rysowanie() {
	printf("\033[31m%c\033[0m ", this->GetSymbol());
}

bool BarszczSosnowskiego::CzyTrujacy() {
	return true;
}

Organizm* BarszczSosnowskiego::WygenerujKopie(Punkt polozenie) {
	Organizm* dziecko = new BarszczSosnowskiego(this->GetSwiat(), polozenie);
	return dziecko;
}

BarszczSosnowskiego::~BarszczSosnowskiego() {
	printf("Zjedzenie Barszczu Sosnowskiego w polozeniu (%i, %i)\n", this->GetPolozenie().GetX(), this->GetPolozenie().GetY());
}