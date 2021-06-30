#pragma once
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <fstream>
#include "Organizm.h"
#include "Zwierze.h"

#define STRZALKA_GORA 72
#define STRZALKA_PRAWO 77
#define STRZALKA_DOL 80
#define STRZALKA_LEWO 75
#define SPACJA 32
#define ENTER 13
#define ESCAPE 27

class Swiat {
private:
	int szerokosc;
	int wysokosc;
	int tura;
	int turaUzyciaZdolnosci;
	int input;
	bool czlowiekZywy;
	double prawdopodobienstwoZasiewu;
	std::vector <Organizm*> organizmy;
	std::vector <Organizm*> aktywneOrganizmy;
	Organizm** mapa = new Organizm*[szerokosc * wysokosc];
public:
	Swiat(int szerokosc, int wysokosc, double prawdopodobienstwoZasiewu);

	void SetPrawdopodobienstwoZasiewu(double prawdopodobienstwoZasiewu);
	void SetTura(int tura);
	void SetTuraUzyciaZdolnosci(int turaUzyciaZdolnosci);
	void SetCzlowiekZywy(bool czlowiekZywy);

	int GetInput() const;
	int GetTura() const;
	int GetTuraUzyciaZdolnosci() const;
	int GetSzerokosc() const;
	int GetWysokosc() const;
	bool GetCzlowiekZywy() const;
	Organizm** GetMapa() const;
	std::vector <Organizm*> GetOrganizmy() const;
	std::vector <Organizm*> GetAktywneOrganizmy() const;
	double GetPrawdopodobienstwoZasiewu() const;

	void ZapiszSymulacje();
	void RysujSwiat();
	void RysujInterfejs();
	void RysujOknoSymulacji();
	void PobierzInput();
	void WykonajTure();
	void ZaktualizujAktywneOrganizmy();
	void DodajOrganizm(Organizm* nowyOrganizm);
	void UsunOrganizm(Organizm* usuwanyOrganizm);

	~Swiat();
};