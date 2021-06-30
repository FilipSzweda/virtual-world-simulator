#include "ZarzadcaSymulacji.h"

ZarzadcaSymulacji::ZarzadcaSymulacji(Swiat* swiat) : swiat(swiat){
}

void ZarzadcaSymulacji::NowaSymulacja() {
    int x = 0, y = 0;
    Punkt polozenieCzlowieka(x, y);
    this->swiat->DodajOrganizm(new Czlowiek(swiat, polozenieCzlowieka));
    for (int i = 1; i < this->swiat->GetSzerokosc(); i++) {
        int wylosowanyOrganizm = rand() % 10;
        Punkt polozenie(i, 0);
        switch (wylosowanyOrganizm) {
        case 0:
            swiat->DodajOrganizm(new BarszczSosnowskiego(swiat, polozenie));
            break;
        case 1:
            swiat->DodajOrganizm(new Guarana(swiat, polozenie));
            break;
        case 2:
            swiat->DodajOrganizm(new Mlecz(swiat, polozenie));
            break;
        case 3:
            swiat->DodajOrganizm(new Trawa(swiat, polozenie));
            break;
        case 4:
            swiat->DodajOrganizm(new WilczeJagody(swiat, polozenie));
            break;
        case 5:
            swiat->DodajOrganizm(new Antylopa(swiat, polozenie));
            break;
        case 6:
            swiat->DodajOrganizm(new Lis(swiat, polozenie));
            break;
        case 7:
            swiat->DodajOrganizm(new Owca(swiat, polozenie));
            break;
        case 8:
            swiat->DodajOrganizm(new Wilk(swiat, polozenie));
            break;
        case 9:
            swiat->DodajOrganizm(new Zolw(swiat, polozenie));
            break;
        }
    }
    for (int i = 1; i < this->swiat->GetWysokosc(); i++) {
        for (int j = 0; j < this->swiat->GetSzerokosc(); j++) {
            int wylosowanyOrganizm = rand() % 10;
            Punkt polozenie(j, i);
            switch (wylosowanyOrganizm) {
            case 0:
                swiat->DodajOrganizm(new BarszczSosnowskiego(swiat, polozenie));
                break;
            case 1:
                swiat->DodajOrganizm(new Guarana(swiat, polozenie));
                break;
            case 2:
                swiat->DodajOrganizm(new Mlecz(swiat, polozenie));
                break;
            case 3:
                swiat->DodajOrganizm(new Trawa(swiat, polozenie));
                break;
            case 4:
                swiat->DodajOrganizm(new WilczeJagody(swiat, polozenie));
                break;
            case 5:
                swiat->DodajOrganizm(new Antylopa(swiat, polozenie));
                break;
            case 6:
                swiat->DodajOrganizm(new Lis(swiat, polozenie));
                break;
            case 7:
                swiat->DodajOrganizm(new Owca(swiat, polozenie));
                break;
            case 8:
                swiat->DodajOrganizm(new Wilk(swiat, polozenie));
                break;
            case 9:
                swiat->DodajOrganizm(new Zolw(swiat, polozenie));
                break;
            }
        }
    }
    this->Symuluj();
}

void ZarzadcaSymulacji::WczytajSymulacje() {
    std::ifstream we("zapis.txt");
    int szerokosc, wysokosc, tura, turaUzyciaZdolnosci, x, y, sila;
    double prawdopodobienstwoZasiewu;
    char symbol;
    we >> szerokosc;
    we >> wysokosc;
    we >> prawdopodobienstwoZasiewu;
    we >> tura;
    we >> turaUzyciaZdolnosci;
    while (!we.eof()) {
        we >> symbol;
        we >> x;
        we >> y;
        we >> sila;
        Punkt polozenie(x, y);
        switch (symbol) {
        case 'x':
            swiat->DodajOrganizm(new BarszczSosnowskiego(swiat, polozenie));
            break;
        case '$':
            swiat->DodajOrganizm(new Guarana(swiat, polozenie));
            break;
        case '*':
            swiat->DodajOrganizm(new Mlecz(swiat, polozenie));
            break;
        case '#':
            swiat->DodajOrganizm(new Trawa(swiat, polozenie));
            break;
        case '+':
            swiat->DodajOrganizm(new WilczeJagody(swiat, polozenie));
            break;
        case 'A':
            swiat->DodajOrganizm(new Antylopa(swiat, polozenie, sila));
            break;
        case 'C':
            swiat->DodajOrganizm(new Czlowiek(swiat, polozenie, sila));
            break;
        case 'L':
            swiat->DodajOrganizm(new Lis(swiat, polozenie, sila));
            break;
        case 'O':
            swiat->DodajOrganizm(new Owca(swiat, polozenie, sila));
            break;
        case 'W':
            swiat->DodajOrganizm(new Wilk(swiat, polozenie, sila));
            break;
        case 'Z':
            swiat->DodajOrganizm(new Zolw(swiat, polozenie, sila));
            break;
        }
    }
    this->Symuluj();
}

void ZarzadcaSymulacji::Symuluj() {
    while (true) {
        swiat->RysujSwiat();
        swiat->PobierzInput();
        system("CLS");
        swiat->WykonajTure();
    }
}

ZarzadcaSymulacji::~ZarzadcaSymulacji() {
}