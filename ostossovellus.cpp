// ostossovellus.cpp
#include "ostossovellus.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

    // Näyttö tyhjennetään edellisistä listoista. Tätä kutsutaan koodissa.
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

    // Näyttää ostoslistan tuotteet ja numeroinnin kun sitä kutsutaan case 2.
void naytaOstoslista(std::string ostosLista[100], int tuoteMaara) {
    clearScreen();

    std::cout << "Ostoslista:" << std::endl;
    for (int i = 0; i < tuoteMaara; i++) {
        std::cout << "Tuote " << i << ": " << ostosLista[i] << std::endl;
    }
}

    // Tallennetaan ostoslista.txt tiedostoon listan ostokset ja virheentarkistus tapauksissa jolloin tiedostoon ei voida tallentaa.
void tallennaOstoslista(std::string ostosLista[100], int tuoteMaara) {
    ofstream tiedosto("ostoslista.txt");

    if (tiedosto.is_open()) {
        for (int i = 0; i < tuoteMaara; i++) {
            tiedosto << ostosLista[i] << endl;
        }
        tiedosto.close();
        cout << "Ostoslista tallennettu tiedostoon 'ostoslista.txt'" << endl;
    } else {
        cout << "Virhe: Tiedostoa 'ostoslista.txt' ei voitu avata" << endl;
    }
}

    // ostoslista.txt tiedostoon tallennetut ostokset ladataan. Jos tiedostoa ei ole niin tulee ilmoitus että tiedosto on luotu.
void lataaOstoslista(std::string ostosLista[100], int &tuoteMaara) {
    ifstream tiedosto("ostoslista.txt");

    if (tiedosto.is_open()) {
        tuoteMaara = 0;
        while (tuoteMaara < 100 && getline(tiedosto, ostosLista[tuoteMaara])) {
            tuoteMaara++;
        }
        tiedosto.close();
        cout << "Ostoslista ladattu tiedostosta 'ostoslista.txt'" << endl;
    } else {
        cout << "Tiedostoa 'ostoslista.txt' ei loydy. Uusi lista aloitettu." << endl;
    }
}

    /* Pää ostosovellus johon on määritetty listan ulkonäkö ja toiminnot. Lista pyörii while loopilla.
     * Switch erilaisille valinnoille ja jokainen case suorittaa eri toiminnot sovelluksessa esim.
     tiedostojen lisäys */
    // ostoSovelluksessa on 100 ostoksen array ja alkuarvo case valinnalle -1. Tuotemäärä on aluksi 0.

int ostosSovellus() {

    std::string ostosLista[100];
    int tuoteMaara = 0;
    int valinta = -1;

    lataaOstoslista(ostosLista, tuoteMaara);

    clearScreen();
    while (valinta != 0) {
        std::cout << "--- Ostoslista ---" << std::endl;
        std::cout << "1 - Lisaa Tuote -" << std::endl;
        std::cout << "2 - Nayta Tuotteet -" << std::endl;
        std::cout << "3 - Merkitse Tuote Ostetuksi -" << std::endl;
        std::cout << "x - Paina 4 Ohjeita varten -"<<std::endl;
        std::cout << "0 - Sulje Sovellus -" << std::endl;
        std::cin >> valinta;

        switch (valinta) {
        case 1:

            {
                if(tuoteMaara < 99)
                {
                    cout<<"Lisaa Ostos"<<endl;
                    cin.ignore();
                    getline(cin, ostosLista[tuoteMaara]);
                    tuoteMaara++;
                }
                break;
            }


        case 2:
        {
            naytaOstoslista(ostosLista, tuoteMaara);
            break;
        }

        case 3:
        {
            naytaOstoslista(ostosLista, tuoteMaara);
            int poista_ostos = 0;
            cout<<"Poista Ostos:";
            cin>>poista_ostos;

            if(tuoteMaara < 1)
            {
                cout<<"Ei Ostoksia";
                break;
            }
            for(int i = poista_ostos; i < tuoteMaara; i++)
            {
                ostosLista[i] = ostosLista[i+1];
            }
            tuoteMaara = tuoteMaara - 1;
            break;
        }
        case 4:
        {
            std::cout<<"Paina 1 Lisääksesi ostettavan tuotteen"<<std::endl;
            std::cout<<"Paina 2 Nayttaaksesi ostoslistan"<<std::endl;
            std::cout<<"Paina 3 Poistaaksesi tuotteita listalta"<<std::endl;
            std::cout<<"Paina 0 Kun haluat sulkea sovelluksen"<<std::endl;
            break;
        }

        case 0:
        {
            tallennaOstoslista(ostosLista, tuoteMaara);
            cout<<"Ohjelma suljetaan"<<endl;
            break;
        }
        }
    }

    return 0;
}
