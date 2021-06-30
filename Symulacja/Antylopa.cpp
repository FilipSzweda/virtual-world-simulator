#include "Antylopa.h"

Antylopa::Antylopa(Swiat* swiat, Punkt& polozenie)
	: Zwierze(swiat, polozenie, SYMBOL_ANTYLOPA, SILA_ANTYLOPA, INICJATYWA_ANTYLOPA) {
	printf("Nowa Antylopa w polozeniu (%i, %i)\n", this->GetPolozenie().GetX(), this->GetPolozenie().GetY());
}

Antylopa::Antylopa(Swiat* swiat, Punkt& polozenie, int sila)
	: Zwierze(swiat, polozenie, SYMBOL_ANTYLOPA, sila, INICJATYWA_ANTYLOPA) {
	printf("Nowa Antylopa w polozeniu (%i, %i)\n", this->GetPolozenie().GetX(), this->GetPolozenie().GetY());
}

void Antylopa::Akcja() {
	std::vector <Punkt> kierunkiDalsze, polozeniaDalsze;
	Punkt goraDalej(this->GetPolozenie().GetX(), this->GetPolozenie().GetY() - 2), prawoDalej(this->GetPolozenie().GetX() + 2, this->GetPolozenie().GetY()), dolDalej(this->GetPolozenie().GetX(), this->GetPolozenie().GetY() + 2), lewoDalej(this->GetPolozenie().GetX() - 2, this->GetPolozenie().GetY());
	kierunkiDalsze.push_back(goraDalej);
	kierunkiDalsze.push_back(prawoDalej);
	kierunkiDalsze.push_back(dolDalej);
	kierunkiDalsze.push_back(lewoDalej);
	for (int i = 0; i < kierunkiDalsze.size(); i++) {
		if (kierunkiDalsze[i].GetX() < this->GetSwiat()->GetSzerokosc() && kierunkiDalsze[i].GetY() < this->GetSwiat()->GetWysokosc() && kierunkiDalsze[i].GetX() >= 0 && kierunkiDalsze[i].GetY() >= 0) {
			polozeniaDalsze.push_back(kierunkiDalsze[i]);
		}
	}
	if (polozeniaDalsze.size() > 0) {
		int indexWylosowanegoPolozenia = rand() % polozeniaDalsze.size();
		this->SetPolozenie(polozeniaDalsze[indexWylosowanegoPolozenia]);
	}
	else {
		this->Zwierze::Akcja();
	}
}

void Antylopa::Rysowanie() {
	printf("%c ", this->GetSymbol());
}

bool Antylopa::CzyUcieklPrzedWalka() {
	int szansaNaUcieczke = rand() % 2;
	if (szansaNaUcieczke == 0) {
		std::vector <Punkt> polozeniaDoUcieczki;
		for (int i = 0; i < this->ZnajdzPolozeniaObok().size(); i++) {
			int index = this->ZnajdzPolozeniaObok()[i].GetX() + this->GetSwiat()->GetSzerokosc() * this->ZnajdzPolozeniaObok()[i].GetY();
			if (this->GetSwiat()->GetMapa()[index] == nullptr) {
				return true;
			}
		}
		return false;
	}
	else {
		return false;
	}
}

Organizm* Antylopa::WygenerujKopie(Punkt polozenie) {
	Organizm* dziecko = new Antylopa(this->GetSwiat(), polozenie);
	return dziecko;
}

Antylopa::~Antylopa() {
	printf("Smierc Antylopy w polozeniu (%i, %i)\n", this->GetPolozenie().GetX(), this->GetPolozenie().GetY());
}