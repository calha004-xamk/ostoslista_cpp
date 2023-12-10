#include "ostossovellus.h"
#include "tiedostohallinta.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// Näyttö tyhjennetään edellisistä listoista. Tätä kutsutaan koodissa.

void clearScreen()
{
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
}

// Näyttää ostoslistan tuotteet ja numeroinnin kun sitä kutsutaan case 2.
void naytaOstoslista(std::string ostosLista[100], int tuoteMaara)
{
    clearScreen();
    std::cout << "Ostoslista:" << std::endl;
    for (int i = 0; i < tuoteMaara; i++) {
        std::cout << "Tuote " << i << ": " << ostosLista[i] << std::endl;
    }
}

/* Pää ostosovellus johon on määritetty listan ulkonäkö ja toiminnot. Lista pyörii while loopilla.
 * Switch erilaisille valinnoille ja jokainen case suorittaa eri toiminnot sovelluksessa esim. tiedostojen lisäys.
 * ostoSovelluksessa on 100 ostoksen array ja alkuarvo case valinnalle -1. Tuotemäärä on aluksi 0.  */

int ostosSovellus()
{

    std::string ostosLista[100];
    int tuoteMaara = 0;
    int valinta = -1;

    clearScreen();
    lataaOstoslista(ostosLista, tuoteMaara);

    while (valinta != 0) {
        std::cout << "\n" << std::endl;
        std::cout << "*--- Ostoslista ---*" << std::endl;
        std::cout << "1 - Lisaa Tuote" << std::endl;
        std::cout << "2 - Nayta Tuotteet" << std::endl;
        std::cout << "3 - Merkitse Tuote Ostetuksi" << std::endl;
        std::cout << "4 - Paina 4 Ohjeita varten" << std::endl;
        std::cout << "0 - Sulje Sovellus" << std::endl;

        std::cout << "\nValinta: ";
        std::cin >> valinta;

        switch (valinta) {
        case 1:

            {
                if (tuoteMaara < 99) {
                    cout << "Lisaa Ostos" << endl;
                    cin.ignore();
                    getline(cin, ostosLista[tuoteMaara]);
                    tuoteMaara++;
                }
                clearScreen();
                break;
            }

        case 2: {
            naytaOstoslista(ostosLista, tuoteMaara);
            break;
        }

        case 3: {
            naytaOstoslista(ostosLista, tuoteMaara);
            int poista_ostos = 0;
            std::cout << "\n" << std::endl;
            cout << "Poista Ostos:";
            cin >> poista_ostos;

            for (int i = poista_ostos; i < tuoteMaara; i++) {
                ostosLista[i] = ostosLista[i + 1];
            }
            tuoteMaara = tuoteMaara - 1;
            clearScreen();
            break;
        }

        case 4: {
            clearScreen();
            std::cout << "Paina 1 Lisaaksesi ostettavan tuotteen" << std::endl;
            std::cout << "Paina 2 Nayttaaksesi ostoslistan" << std::endl;
            std::cout << "Paina 3 Poistaaksesi tuotteita listalta" << std::endl;
            std::cout << "Paina 0 Kun haluat sulkea sovelluksen" << std::endl;
            break;
        }

        case 0: {
            tallennaOstoslista(ostosLista, tuoteMaara);
            cout << "Ohjelma suljetaan" << endl;
            std::cout << "\n" << std::endl;
            break;
        }
        }
    }

    return 0;
}
