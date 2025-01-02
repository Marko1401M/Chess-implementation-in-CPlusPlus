#ifndef POLJE_H
#define POLJE_H
#include "../Figure/figura.h"

class Polje{
    public:
        Polje(const int, const int);
        Polje(const int, const int, Figura*);
        friend ostream& operator <<(ostream&, Polje*);
        Figura* getFigura() const;
        void setFigura(Figura *);
        int getX() const;
        int getY() const;
    private:
        const int x;
        const int y;
        Figura *figura;
};

#endif