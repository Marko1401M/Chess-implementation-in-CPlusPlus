#ifndef KRALJ_H
#define KRALJ_H

#include "figura.h"

class Kralj : public Figura{    
    public:
            Kralj(const char);
            bool proveriPotez(const int , const int , const int , const int , Tabla* ) override;
};

#endif