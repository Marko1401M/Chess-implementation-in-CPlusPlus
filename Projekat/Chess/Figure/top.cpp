#include "top.h"
using namespace std;
#include "../Igra/tabla.h"
Top :: Top(const char boja) : Figura(boja, 'T') {}

bool Top :: proveriPotez(int startY, int startX, int endY, int endX, Tabla* tabla) {
    //cout << startY << ' ' << startX << ' ' << endY << ' ' << endX << endl;
    if(endY > startY && startX == endX){
        for(int i = startY + 1; i < endY; i++){
            if(tabla->getPolje(i,startX) != nullptr) ;
        }
        if(tabla->getPolje(endY,endX) == nullptr || tabla->getPolje(endY,endX)->getBoja() != this->getBoja()) return true;
        return false;
    }
    else if(endY < startY && startX == endX){
        for(int i = startY - 1; i > endY; i--){
            if(tabla->getPolje(i,startX) != nullptr) return false;
        }
        if(tabla->getPolje(endY,endX) == nullptr || tabla->getPolje(endY,endX)->getBoja() != this->getBoja()) return true;
        return false;
    }
    else if(endX > startX && startY == endY){
        for(int i = startX + 1; i < endX; i++){
            if(tabla->getPolje(startY,i) != nullptr) return false;
        }
        if(tabla->getPolje(endY,endX) == nullptr || tabla->getPolje(endY,endX)->getBoja() != this->getBoja()) return true;
        return false;
    }
    else if(endX < startX && startY == endY){
        for(int i = startX - 1; i > endX; i--){
            if(tabla->getPolje(startY,i) != nullptr) return false;
        }
        if(tabla->getPolje(endY,endX) == nullptr || tabla->getPolje(endY,endX)->getBoja() != this->getBoja()) return true;
        return false;
    }
    return false;
}
