#ifndef KRALJICA_H
#define KRALJICA_H

#include "figura.h"

class Kraljica : public Figura{
    public:
            Kraljica(const char);
            bool proveriPotez(const int , const int , const int , const int , Tabla* ) override;
};

#endif