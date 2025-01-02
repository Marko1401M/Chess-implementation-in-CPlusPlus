#ifndef LOVAC_H
#define LOVAC_H

#include "figura.h"

class Lovac : public Figura{
    public:
            Lovac(const char boja);
            bool proveriPotez(const int , const int , const int , const int , Tabla* ) override;
    private:
};

#endif
