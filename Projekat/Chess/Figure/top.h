#ifndef TOP_H
#define TOP_H

#include "figura.h"


class Top : public Figura{
    public:
            Top(const char boja);
            bool proveriPotez(int startX, int startY, int endX, int endY, Tabla* tabla) override;
    private:
};

#endif
