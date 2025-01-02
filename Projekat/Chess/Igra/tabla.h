#ifndef TABLA_H
#define TABLA_H

#include <list>
#include "potez.h"
#include "../Figure/figura.h"
#include <stdio.h>
#include "../Figure/pijun.h"
#include "../Figure/top.h"
#include "../Figure/lovac.h"
#include "../Figure/kraljica.h"
#include "../Figure/kralj.h"
#include "../Figure/skakac.h"
#include "../Izuzeci/nevalidan_potez_exception.h"
#include "../Izuzeci/potez_izvan_table_exception.h"
#include "../Izuzeci/igrac_nije_na_potezu_exception.h"
#include "../Izuzeci/prazno_polje_exception.h"
#include "polje.h"
#include <exception>

using namespace std;


class Tabla{
        public: 
                Tabla();
                ~Tabla();
                void inicijalizujTablu();
                Figura* getPolje(const int, const int);
                bool proveriPolje(const char, const int , const int ) const;
                void ucitajPotez();
                bool odigrajPotez(const int startX, const int startY, const int endX, const int endY);
                void stampajTablu() const;
                void prikaziPoteze() const;
                int proveriKraj() const;// 1 beli je pobedio, -1 crni je pobedio, 0 jos uvek traje partija
                void stampajPojedene() const;
                void proveriSah();
        private:
                char naPotezu;
                static int odigranoPoteza;
                Polje*** polja;
                list <Potez> potezi;
                list <Figura*> pojedeneBeli;
                list <Figura*> pojedeneCrni;

};          

#endif
