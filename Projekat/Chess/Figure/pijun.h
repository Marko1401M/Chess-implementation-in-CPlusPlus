#ifndef PIJUN_H
#define PIJUN_H

#include "figura.h"

using namespace std;

class Pijun : public Figura{
    public:
        Pijun(const char boja);
        bool proveriPotez(const int , const int , const int , const int , Tabla* ) override;
    private:
        bool pomeren = false;
};

#endif