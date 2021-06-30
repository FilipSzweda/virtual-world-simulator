#pragma once
#include <vector>
#include "Punkt.h"
class Swiat;

class Organizm {
private:
	Swiat* swiat;
	Punkt polozenie;
	char symbol;
	int sila;
	int inicjatywa;
	bool zywy;
public:
	Organizm(Swiat* swiat, Punkt polozenie, char symbol, int sila, int inicjatywa);

	virtual void Akcja() = 0;
	virtual void Kolizja(Organizm* organizmKolidujacy, Punkt polozeniePoczatkowe) = 0;
	virtual void Rozmnazanie(Organizm* organizmKolidujacy, Punkt polozeniePoczatkowe);
	virtual void Walka(Organizm* organizmKolidujacy, Punkt polozeniePoczatkowe);
	virtual void Odbicie(Punkt polozeniePoczatkowe);
	virtual void TarczaAlzura(Punkt polozeniePoczatkowe);
	virtual void Ucieczka(Organizm* organizmAtakujacy);
	virtual void Rysowanie() = 0;
	virtual Organizm* WygenerujKopie(Punkt polozenie) = 0;

	virtual void DodajOrganizmNaMape(Punkt polozenie);
	virtual void UsunOrganizmZMapy(Punkt polozenie);
	virtual bool CzyOdbilAtak(Organizm* organizmAtakujacy);
	virtual bool CzyUcieklPrzedWalka();
	virtual bool CzyBonusSily();
	virtual bool CzyTrujacy();
	virtual bool CzyZwierze();
	virtual bool CzyTarczaAlzura();
	virtual bool SprawdzKolizje(Organizm* organizm);

	std::vector <Punkt> ZnajdzPolozeniaObok();
	int ObliczIndexNaMapie(Punkt polozenieDoIndexu);

	Swiat *GetSwiat() const;
	Punkt GetPolozenie() const;
	char GetSymbol() const;
	int GetSila() const;
	int GetInicjatywa() const;
	bool GetZywy() const;

	void SetSwiat(Swiat* swiat);
	void SetPolozenie(Punkt polozenie);
	void SetPolozenieX(int x);
	void SetPolozenieY(int y);
	void SetSymbol(char symbol);
	void SetSila(int sila);
	void SetZywy(bool zywy);

	virtual ~Organizm();
};
