#include "Czlowiek.h"

Czlowiek::Czlowiek(Swiat* swiat, Punkt& polozenie)
	: Zwierze(swiat, polozenie, SYMBOL_CZLOWIEK, SILA_CZLOWIEK, INICJATYWA_CZLOWIEK) {
    printf("Nowy Czlowiek w polozeniu (%i, %i)\n", this->GetPolozenie().GetX(), this->GetPolozenie().GetY());
    this->GetSwiat()->SetCzlowiekZywy(true);
}

Czlowiek::Czlowiek(Swiat* swiat, Punkt& polozenie, int sila)
    : Zwierze(swiat, polozenie, SYMBOL_CZLOWIEK, sila, INICJATYWA_CZLOWIEK) {
    printf("Nowy Czlowiek w polozeniu (%i, %i)\n", this->GetPolozenie().GetX(), this->GetPolozenie().GetY());
    this->GetSwiat()->SetCzlowiekZywy(true);
}

void Czlowiek::Akcja() {
    switch ((this->GetSwiat()->GetInput())) {
    case STRZALKA_GORA:
        if (this->GetPolozenie().GetY() - 1 >= 0) {
            this->SetPolozenieY(this->GetPolozenie().GetY() - 1);
        }
        break;
    case STRZALKA_PRAWO:
        if (this->GetPolozenie().GetX() + 1 < this->GetSwiat()->GetSzerokosc()) {
            this->SetPolozenieX(this->GetPolozenie().GetX() + 1);
        }
        break;
    case STRZALKA_DOL:
        if (this->GetPolozenie().GetY() + 1 < this->GetSwiat()->GetWysokosc()) {
            this->SetPolozenieY(this->GetPolozenie().GetY() + 1);
        }
        break;
    case STRZALKA_LEWO:
        if (this->GetPolozenie().GetX() - 1 >= 0) {
            this->SetPolozenieX(this->GetPolozenie().GetX() - 1);
        }
        break;
    case SPACJA:
        if (this->GetSwiat()->GetTuraUzyciaZdolnosci() < 0 || this->GetSwiat()->GetTura() - this->GetSwiat()->GetTuraUzyciaZdolnosci() > 10) {
            this->GetSwiat()->SetTuraUzyciaZdolnosci(this->GetSwiat()->GetTura());
            printf("Aktywowano zdolnosc Tarczy Azlura!\n");
        }
        else {
            printf("Nie mozna aktywowac zdolnosci Tarczy Azlura!\n");
        }     
        break;
    case ENTER:
        break;
    }
}

bool Czlowiek::CzyTarczaAlzura() {
    if (this->GetSwiat()->GetTura() - this->GetSwiat()->GetTuraUzyciaZdolnosci() <= 5 && this->GetSwiat()->GetTuraUzyciaZdolnosci() >= 0) {
        return true;
    }
    else {
        return false;
    }
}

void Czlowiek::Rysowanie() {
	printf("%c ", this->GetSymbol());
}

Organizm* Czlowiek::WygenerujKopie(Punkt polozenie) {
    Organizm* dziecko = new Czlowiek(this->GetSwiat(), polozenie);
    return dziecko;
}

Czlowiek::~Czlowiek() {
    printf("Smierc Czlowieka w polozeniu(%i, %i)\n", this->GetPolozenie().GetX(), this->GetPolozenie().GetY());
    this->GetSwiat()->SetCzlowiekZywy(false);
}