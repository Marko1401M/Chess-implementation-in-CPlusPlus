#include "polje.h"
#include <iostream>

using namespace std;

Polje :: Polje(const int x, const int y) : x(x), y(y), figura(nullptr){}

Polje :: Polje(const int x, const int y, Figura *f) : x(x), y(y), figura(f) {}

ostream& operator <<(ostream& out, Polje *p){
    if(p->getFigura() != nullptr){
        return out << p->getFigura();
    }
    else{
        return out << " ";
    }
}

Figura* Polje :: getFigura() const{
    return figura;
}

void Polje :: setFigura(Figura* f) {
    figura = f;
}

int Polje :: getX() const {
    return x;
}

int Polje :: getY() const{
    return y;
}