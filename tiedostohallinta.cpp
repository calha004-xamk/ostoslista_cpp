#include "tiedostohallinta.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// Tallennetaan ostoslista.txt tiedostoon listan ostokset ja virheentarkistus
// tapauksissa jolloin tiedostoon ei voida tallentaa.
void tallennaOstoslista(std::string ostosLista[100], int tuoteMaara)
{
    ofstream tiedosto("ostoslista.txt");

    if (tiedosto.is_open()) {
        for (int i = 0; i < tuoteMaara; i++) {
            tiedosto << ostosLista[i] << endl;
        }
        tiedosto.close();
        cout << "Ostoslista tallennettu tiedostoon 'ostoslista.txt'" << endl;
    } else {
        cout << "Virhe: Tiedostoon 'ostoslista.txt' ei voitu tallentaa" << endl;
    }
}

// ostoslista.txt tiedostoon tallennetut ostokset ladataan. Jos tiedostoa ei ole
// niin tulee ilmoitus, että tiedosto on luotu.
void lataaOstoslista(std::string ostosLista[100], int& tuoteMaara)
{
    ifstream tiedosto("ostoslista.txt");

    if (tiedosto.is_open()) {
        tuoteMaara = 0;
        while (tuoteMaara < 100 && getline(tiedosto, ostosLista[tuoteMaara])) {
            tuoteMaara++;
        }
        tiedosto.close();
        cout << "Ostoslista ladattu tiedostosta 'ostoslista.txt'" << endl;
    } else {
        cout << "Tiedostoa 'ostoslista.txt' ei loydy. Uusi lista aloitettu."
             << endl;
    }
}
