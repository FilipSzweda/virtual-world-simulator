#include "Swiat.h"

Swiat::Swiat(int szerokosc, int wysokosc, double prawdopodobienstwoZasiewu)
	: szerokosc(szerokosc), wysokosc(wysokosc), prawdopodobienstwoZasiewu(prawdopodobienstwoZasiewu) {
	for (int i = 0; i < this->szerokosc * this->wysokosc; i++) {
		this->mapa[i] = nullptr;
	}
	this->tura = 0;
	this->input = 0;
	this->czlowiekZywy = false;
	this->turaUzyciaZdolnosci = -1;
	srand(time(NULL) + rand());
}

int Swiat::GetInput() const {
	return this->input;
}

int Swiat::GetTura() const {
	return this->tura;
}

int Swiat::GetTuraUzyciaZdolnosci() const {
	return this->turaUzyciaZdolnosci;
}

int Swiat::GetSzerokosc() const {
	return this->szerokosc;
}

int Swiat::GetWysokosc() const {
	return this->wysokosc;
}

bool Swiat::GetCzlowiekZywy() const {
	return this->czlowiekZywy;
}

Organizm** Swiat::GetMapa() const {
	return mapa;
}

std::vector <Organizm*> Swiat::GetOrganizmy() const {
	return this->organizmy;
}

std::vector <Organizm*> Swiat::GetAktywneOrganizmy() const {
	return this->aktywneOrganizmy;
}

double Swiat::GetPrawdopodobienstwoZasiewu() const {
	return this->prawdopodobienstwoZasiewu;
}

void Swiat::SetPrawdopodobienstwoZasiewu(double prawdopodobienstwoZasiewu) {
	this->prawdopodobienstwoZasiewu = prawdopodobienstwoZasiewu;
}

void Swiat::SetTura(int tura) {
	this->tura = tura;
}

void Swiat::SetTuraUzyciaZdolnosci(int turaUzyciaZdolnosci) {
	this->turaUzyciaZdolnosci = turaUzyciaZdolnosci;
}

void Swiat::SetCzlowiekZywy(bool czlowiekZywy) {
	this->czlowiekZywy = czlowiekZywy;
}

void Swiat::ZaktualizujAktywneOrganizmy() {
	this->aktywneOrganizmy.clear();
	for (int i = 0; i < this->organizmy.size(); i++) {
		this->aktywneOrganizmy.push_back(this->organizmy[i]);
	}
}

void Swiat::DodajOrganizm(Organizm* nowyOrganizm) {
	bool organizmDodany = false;
	for (int i = 0; i < this->organizmy.size(); i++) {
		if (nowyOrganizm->GetInicjatywa() > this->organizmy[i]->GetInicjatywa()) {
			this->organizmy.insert(this->organizmy.begin() + i, nowyOrganizm);
			organizmDodany = true;
			break;
		}
	}
	if (organizmDodany == false) {
		this->organizmy.push_back(nowyOrganizm);
	}
}

void Swiat::UsunOrganizm(Organizm* usuwanyOrganizm) {
	this->organizmy.erase(std::find(this->organizmy.begin(), this->organizmy.end() - 1, usuwanyOrganizm));
	delete(usuwanyOrganizm);
}

void Swiat::RysujSwiat() {
	this->RysujOknoSymulacji();
	this->RysujInterfejs();
}

void Swiat::RysujOknoSymulacji() {
	printf("%c", (char)201);
	for (int i = 0; i < 2 * this->szerokosc; i++) {
		printf("%c", (char)205);
	}
	printf("%c", (char)187);
	printf("\n");
	for (int i = 0; i < this->szerokosc * this->wysokosc; i++) {
		if (i % this->szerokosc == 0) {
			printf("%c", (char)186);
		}
		if (this->mapa[i] != nullptr) {
			mapa[i]->Rysowanie();
		}
		else {
			printf("  ");
		}
		if ((i + 1) % this->szerokosc == 0) {
			printf("%c\n", (char)186);
		}
	}
	printf("%c", (char)200);
	for (int i = 0; i < 2 * this->szerokosc; i++) {
		printf("%c", (char)205);
	}
	printf("%c", (char)188);
	printf("\n");
}

void Swiat::RysujInterfejs() {
	printf("Strzalki klawiatury - sterowanie\n");
	printf("Spacja - zdolnosc Tarczy Alzura\n");
	printf("Enter - pominiecie tury\n");
	printf("Escape - zapis symulacji\n");
	printf("Tura: %i\n", this->GetTura());
	if (this->GetTuraUzyciaZdolnosci() > 0 && 6 - (this->GetTura() - this->GetTuraUzyciaZdolnosci()) > 0) {
		printf("Tura zdolnosci: %i\n", 6 - (this->GetTura() - this->GetTuraUzyciaZdolnosci()));
	}
	else {
		printf("Pozostale tury zdolnosci: 0\n");
	}
}

void Swiat::WykonajTure() {
	this->ZaktualizujAktywneOrganizmy();
	for (int i = 0; i < this->aktywneOrganizmy.size(); i++) {
		if (this->aktywneOrganizmy[i]->GetZywy() == true && this->GetMapa()[this->aktywneOrganizmy[i]->ObliczIndexNaMapie(this->aktywneOrganizmy[i]->GetPolozenie())] != nullptr) {
			Punkt polozeniePoczatkowe = this->aktywneOrganizmy[i]->GetPolozenie();
			this->aktywneOrganizmy[i]->Akcja();
			if (this->aktywneOrganizmy[i]->CzyZwierze() == true) {
				bool kolizjaWystapila = false;
				for (int j = 0; j < this->organizmy.size(); j++) {
					if (organizmy[j]->GetZywy() == true && aktywneOrganizmy[i] != organizmy[j] && this->aktywneOrganizmy[i]->SprawdzKolizje(this->organizmy[j])) {
						this->aktywneOrganizmy[i]->Kolizja(this->organizmy[j], polozeniePoczatkowe);
						kolizjaWystapila = true;
						break;
					}
				}
				if (!kolizjaWystapila) {
					this->aktywneOrganizmy[i]->UsunOrganizmZMapy(polozeniePoczatkowe);
					this->aktywneOrganizmy[i]->DodajOrganizmNaMape(this->aktywneOrganizmy[i]->GetPolozenie());
				}
			}
		}
	}
	for (int i = 0; i < organizmy.size(); i++) {
		if (this->organizmy[i]->GetZywy() == false) {
			this->UsunOrganizm(this->organizmy[i]);
		}
	}
	this->tura++;
}

void Swiat::PobierzInput() {
	bool waitingForInput = true;
	while (waitingForInput) {
		switch ((this->input = _getch())) {
		case STRZALKA_GORA:
			waitingForInput = false;
			break;
		case STRZALKA_PRAWO:
			waitingForInput = false;
			break;
		case STRZALKA_DOL:
			waitingForInput = false;
			break;
		case STRZALKA_LEWO:
			waitingForInput = false;
			break;
		case SPACJA:
			if ((this->GetTuraUzyciaZdolnosci() < 0 || this->GetTura() - this->GetTuraUzyciaZdolnosci() > 10) && this->czlowiekZywy == true) {
				this->SetTuraUzyciaZdolnosci(this->GetTura());
				printf("Aktywowano zdolnosc Tarczy Alzura!\n");
			}
			else {
				printf("Nie mozna aktywowac zdolnosci Tarczy Alzura!\n");
			}
			break;
		case ENTER:
			waitingForInput = false;
			break;
		case ESCAPE:
			this->ZapiszSymulacje();
			printf("Symulacja zostala zapisana!\n");
			break;
		}
	}
}

void Swiat::ZapiszSymulacje() {
	std::ofstream wyjscie;
	wyjscie.open("zapis.txt");
	wyjscie << this->szerokosc << " " << this->wysokosc << " " << this->prawdopodobienstwoZasiewu << " " << this->tura << " " << this->turaUzyciaZdolnosci << "\n";
	for (int i = 0; i < organizmy.size(); i++) {
		wyjscie << organizmy[i]->GetSymbol() << " " << organizmy[i]->GetPolozenie().GetX() << " " << organizmy[i]->GetPolozenie().GetY() << " " << organizmy[i]->GetSila() << "\n";
	}
	wyjscie.close();
}

Swiat::~Swiat(){
	for (int i = 0; i < this->organizmy.size(); i++) {
		delete(this->organizmy[i]);
	}
	for (int i = 0; i < this->aktywneOrganizmy.size(); i++) {
		delete(this->aktywneOrganizmy[i]);
	}
	organizmy.clear();
	aktywneOrganizmy.clear();
}