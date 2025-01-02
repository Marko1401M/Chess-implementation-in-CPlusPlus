#include "potez.h"

using namespace std;
#include <iostream>
#include <string>

Potez :: Potez(const char startY, const int startX, const char endY, const int endX, const int redniBroj) : startX(startX), startY(startY), endX(endX), endY(endY), redniBroj(redniBroj) {}

string Potez :: getPotez() const{
    string pom = "";
    pom = to_string(redniBroj) + ":" + startY + to_string(startX) + "->" + endY + to_string(endX);
    return pom;
}

ostream& operator <<(ostream& out,const Potez& potez){
    return out << potez.getPotez();
}