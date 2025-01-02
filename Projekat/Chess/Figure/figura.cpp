#include "figura.h"
using namespace std;

Figura :: Figura(const char boja, const char tip) : boja(boja), tip(tip) {}

char Figura :: getBoja() const{
    return boja;
}

char Figura :: getTip() const{
    return tip;
}

ostream& operator <<(ostream& out, Figura* f){
    return out << f->getBoja() << ' ' << f->tip;
}