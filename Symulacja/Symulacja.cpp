#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <tchar.h>
#include "windows.h"
#include "ZarzadcaSymulacji.h"
#include "Swiat.h"
#include "Organizm.h"
#include "Zwierze.h"
#include "Antylopa.h"
#include "Lis.h"
#include "Owca.h"
#include "Wilk.h"
#include "Zolw.h"
#include "Czlowiek.h"
#include "Roslina.h"
#include "BarszczSosnowskiego.h"
#include "Guarana.h"
#include "Mlecz.h"
#include "Trawa.h"
#include "WilczeJagody.h"

int main() {
    SetConsoleTitle(_T("Filip Szweda 184738"));
    printf("n - Nowa Symulacja\n");
    printf("w - Wczytaj Symulacje\n");
    printf("o - Oznaczenia\n");
    bool waitingForInput = true;
    char input;
    while (waitingForInput) {
        scanf("%c", &input);
        if (input == 'n') {
            int szerokosc, wysokosc;
            double prawdopodobienstwoZasiewu;
            do {
                printf("Szerokosc swiata:\n");
                scanf("%i", &szerokosc);
            } while (szerokosc < 1);
            do {
                printf("Wysokosc swiata:\n");
                scanf("%i", &wysokosc);
            } while (wysokosc < 1);
            do {
                printf("Prawdopodobienstwo zasiewu:\n");
                scanf("%lf", &prawdopodobienstwoZasiewu);
            } while (prawdopodobienstwoZasiewu < 0);
            Swiat swiat(szerokosc, wysokosc, prawdopodobienstwoZasiewu);
            ZarzadcaSymulacji zarzadcaSymulacji(&swiat);
            zarzadcaSymulacji.NowaSymulacja();
        }
        else if (input == 'w') {
            std::ifstream we("zapis.txt");
            int szerokosc, wysokosc, tura, turaUzyciaZdolnosci, x, y, sila;
            double prawdopodobienstwoZasiewu;
            char symbol;
            we >> szerokosc;
            we >> wysokosc;
            we >> prawdopodobienstwoZasiewu;
            we >> tura;
            we >> turaUzyciaZdolnosci;
            Swiat swiat(szerokosc, wysokosc, prawdopodobienstwoZasiewu);
            swiat.SetTuraUzyciaZdolnosci(tura);
            swiat.SetTuraUzyciaZdolnosci(turaUzyciaZdolnosci);
            ZarzadcaSymulacji zarzadcaSymulacji(&swiat);
            zarzadcaSymulacji.WczytajSymulacje();
        }
        else if (input == 'o') {
            printf("A - Antylopa\n");
            printf("C - Czlowiek\n");
            printf("L - Lis\n");
            printf("O - Owca\n");
            printf("W - Wilk\n");
            printf("Z - Zolw\n");
            printf("\033[31mx\033[0m - Barszcz Sosnowskiego\n");
            printf("\033[94m$\033[0m - Guarana\n");
            printf("\033[93m*\033[0m - Mlecz\n");
            printf("\033[92m#\033[0m - Trawa\n");
            printf("\033[91m+\033[0m - Wilcze Jagody\n");
        }
    }
    return 0;
}