#include "Organizm.h"
#include "Swiat.h"
#include "Zwierze.h"

Organizm::Organizm(Swiat* swiat, Punkt polozenie, char symbol, int sila, int inicjatywa)
	: swiat(swiat), polozenie(polozenie), symbol(symbol), sila(sila), inicjatywa(inicjatywa) {
	this->DodajOrganizmNaMape(this->GetPolozenie());
	this->zywy = true;
}

bool Organizm::CzyOdbilAtak(Organizm* organizmAtakujacy) {
	return false;
}

bool Organizm::CzyUcieklPrzedWalka() {
	return false;
}

bool Organizm::CzyBonusSily() {
	return false;
}

bool Organizm::CzyTrujacy() {
	return false;
}

bool Organizm::CzyZwierze() {
	return false;
}

bool Organizm::CzyTarczaAlzura() {
	return false;
}

void Organizm::DodajOrganizmNaMape(Punkt polozenie) {
	this->GetSwiat()->GetMapa()[this->ObliczIndexNaMapie(polozenie)] = this;
}

void Organizm::UsunOrganizmZMapy(Punkt polozenie) {
	this->GetSwiat()->GetMapa()[this->ObliczIndexNaMapie(polozenie)] = nullptr;
}

bool Organizm::SprawdzKolizje(Organizm* organizm) {
	if (this->GetPolozenie() == organizm->GetPolozenie()) {
		return true;
	}
	else {
		return false;
	}
}

void Organizm::Rozmnazanie(Organizm* organizmKolidujacy, Punkt polozeniePoczatkowe) {
	this->SetPolozenie(polozeniePoczatkowe);
	std::vector <Punkt> polozeniaDlaDziecka;
	for (int i = 0; i < organizmKolidujacy->ZnajdzPolozeniaObok().size(); i++) {
		if (organizmKolidujacy->GetSwiat()->GetMapa()[organizmKolidujacy->ObliczIndexNaMapie(organizmKolidujacy->ZnajdzPolozeniaObok()[i])] == nullptr) {
			polozeniaDlaDziecka.push_back(organizmKolidujacy->ZnajdzPolozeniaObok()[i]);
		}
	}
	if (polozeniaDlaDziecka.size() > 0) {
		int indeksWylosowanegoPolozenia = rand() % polozeniaDlaDziecka.size();
		organizmKolidujacy->GetSwiat()->DodajOrganizm(organizmKolidujacy->WygenerujKopie(polozeniaDlaDziecka[indeksWylosowanegoPolozenia]));
	}
}

void Organizm::Walka(Organizm* organizmKolidujacy, Punkt polozeniePoczatkowe) {
	if (organizmKolidujacy->CzyTrujacy() == true) {
		this->UsunOrganizmZMapy(polozeniePoczatkowe);
		this->UsunOrganizmZMapy(this->GetPolozenie());
		organizmKolidujacy->SetZywy(false);
		this->SetZywy(false);
	}
	else {
		if (organizmKolidujacy->CzyTarczaAlzura() == true) {
			this->TarczaAlzura(polozeniePoczatkowe);
		}
		else {
			if (this->GetSila() >= organizmKolidujacy->GetSila()) {
				if (organizmKolidujacy->CzyOdbilAtak(this) == true) {
					this->Odbicie(polozeniePoczatkowe);
				}
				else {
					this->UsunOrganizmZMapy(polozeniePoczatkowe);
					this->DodajOrganizmNaMape(this->GetPolozenie());
					if (organizmKolidujacy->CzyUcieklPrzedWalka() == true) {
						organizmKolidujacy->Ucieczka(this);
					}
					else {
						if (organizmKolidujacy->CzyBonusSily() == true) {
							this->SetSila(this->GetSila() + 3);
						}
						organizmKolidujacy->SetZywy(false);
					}
				}
			}
			else {
				if (this->CzyUcieklPrzedWalka() == true) {
					this->UsunOrganizmZMapy(polozeniePoczatkowe);
					this->Ucieczka(organizmKolidujacy);
				}
				else {
					this->UsunOrganizmZMapy(polozeniePoczatkowe);
					this->SetZywy(false);
				}
			}
		}
	}
}

void Organizm::Odbicie(Punkt polozeniePoczatkowe) {
	this->SetPolozenie(polozeniePoczatkowe);
}

void Organizm::TarczaAlzura(Punkt polozeniePoczatkowe) {
	Punkt polozenieNaTarczyAlzura = this->GetPolozenie();
	if (this->ZnajdzPolozeniaObok().size() > 0) {
		int indeksWylosowanegoPolozenia = rand() % this->ZnajdzPolozeniaObok().size();
		this->SetPolozenie(this->ZnajdzPolozeniaObok()[indeksWylosowanegoPolozenia]);
	}
	if (this->GetPolozenie() == polozenieNaTarczyAlzura) {
		this->UsunOrganizmZMapy(polozeniePoczatkowe);
		this->SetZywy(false);
	}
	else {
		bool kolizjaWystapila = false;
		for (int i = 0; i < this->GetSwiat()->GetOrganizmy().size(); i++) {
			if (this != this->GetSwiat()->GetOrganizmy()[i] && this->SprawdzKolizje(this->GetSwiat()->GetOrganizmy()[i])) {
				this->Kolizja(this->GetSwiat()->GetOrganizmy()[i], polozeniePoczatkowe);
				kolizjaWystapila = true;
				break;
			}
		}
		if (!kolizjaWystapila) {
			this->UsunOrganizmZMapy(polozeniePoczatkowe);
			this->DodajOrganizmNaMape(this->GetPolozenie());
		}
	}
}

void Organizm::Ucieczka(Organizm* organizmAtakujacy) {
	std::vector <Punkt> polozeniaDoUcieczki;
	for (int i = 0; i < this->ZnajdzPolozeniaObok().size(); i++) {
		if (this->GetSwiat()->GetMapa()[this->ObliczIndexNaMapie(this->ZnajdzPolozeniaObok()[i])] == nullptr) {
			polozeniaDoUcieczki.push_back(this->ZnajdzPolozeniaObok()[i]);
		}
	}
	int indeksWylosowanegoPolozenia = rand() % polozeniaDoUcieczki.size();
	this->SetPolozenie(polozeniaDoUcieczki[indeksWylosowanegoPolozenia]);
	this->DodajOrganizmNaMape(this->GetPolozenie());
}

Swiat* Organizm::GetSwiat() const {
	return this->swiat;
}

Punkt Organizm::GetPolozenie() const {
	return this->polozenie;
}

char Organizm::GetSymbol() const {
	return this->symbol;
}

int Organizm::GetSila() const {
	return this->sila;
}

int Organizm::GetInicjatywa() const {
	return this->inicjatywa;
}

bool Organizm::GetZywy() const {
	return this->zywy;
}

void Organizm::SetSwiat(Swiat* swiat) {
	this->swiat = swiat;
}

void Organizm::SetPolozenie(Punkt polozenie) {
	this->polozenie.SetX(polozenie.GetX());
	this->polozenie.SetY(polozenie.GetY());
}

void Organizm::SetPolozenieX(int x) {
	this->polozenie.SetX(x);
}

void Organizm::SetPolozenieY(int y) {
	this->polozenie.SetY(y);
}

void Organizm::SetSymbol(char symbol) {
	this->symbol = symbol;
}

void Organizm::SetSila(int sila) {
	this->sila = sila;
}

void Organizm::SetZywy(bool zywy) {
	this->zywy = zywy;
}

std::vector <Punkt> Organizm::ZnajdzPolozeniaObok() {
	std::vector <Punkt> kierunki, polozenia;
	Punkt gora(this->GetPolozenie().GetX(), this->GetPolozenie().GetY() - 1), prawo(this->GetPolozenie().GetX() + 1, this->GetPolozenie().GetY()), dol(this->GetPolozenie().GetX(), this->GetPolozenie().GetY() + 1), lewo(this->GetPolozenie().GetX() - 1, this->GetPolozenie().GetY());
	kierunki.push_back(gora);
	kierunki.push_back(prawo);
	kierunki.push_back(dol);
	kierunki.push_back(lewo);
	for (int i = 0; i < kierunki.size(); i++) {
		if (kierunki[i].GetX() < this->GetSwiat()->GetSzerokosc() && kierunki[i].GetY() < this->GetSwiat()->GetWysokosc() && kierunki[i].GetX() >= 0 && kierunki[i].GetY() >= 0) {
			polozenia.push_back(kierunki[i]);
		}
	}
	return polozenia;
}

int Organizm::ObliczIndexNaMapie(Punkt polozenieDoIndexu) {
	int indexNaMapie = polozenieDoIndexu.GetX() + this->GetSwiat()->GetSzerokosc() * polozenieDoIndexu.GetY();
	return indexNaMapie;
}

Organizm::~Organizm() {
}