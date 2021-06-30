#include "Roslina.h"
#include "Swiat.h"

Roslina::Roslina(Swiat* swiat, Punkt polozenie, char symbol, int sila)
	: Organizm(swiat, polozenie, symbol, sila, INICJATYWA_ROSLINA) {
}

void Roslina::Akcja() {
	int zasiew = rand() % (int)(1 / this->GetSwiat()->GetPrawdopodobienstwoZasiewu());
	if (zasiew == 0) {
		std::vector <Punkt> polozeniaDlaRosliny;
		for (int i = 0; i < this->ZnajdzPolozeniaObok().size(); i++) {
			if (this->GetSwiat()->GetMapa()[this->ObliczIndexNaMapie(this->ZnajdzPolozeniaObok()[i])] == nullptr) {
				polozeniaDlaRosliny.push_back(this->ZnajdzPolozeniaObok()[i]);
			}
		}
		if (polozeniaDlaRosliny.size() > 0) {
			int indexWylosowanegoPolozenia = rand() % polozeniaDlaRosliny.size();
			this->GetSwiat()->DodajOrganizm(this->WygenerujKopie(polozeniaDlaRosliny[indexWylosowanegoPolozenia]));
		}
	}
}

void Roslina::Kolizja(Organizm* organizmKoliduj¹cy, Punkt polozeniePoczatkowe) {
	this->UsunOrganizmZMapy(polozeniePoczatkowe);
	this->SetZywy(false);
}

Roslina::~Roslina() {
}