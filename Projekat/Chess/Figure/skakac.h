#ifndef SKAKAC_H
#define SKAKAC_H

#include "figura.h"

class Skakac : public Figura{ //Skakac je konj, ali slovo K je zauzeto zbog kralja pa sam stavio S da bi se razlikovali
    public:
        Skakac(const char);
        bool proveriPotez(const int , const int , const int , const int , Tabla* ) override;

};

#endif