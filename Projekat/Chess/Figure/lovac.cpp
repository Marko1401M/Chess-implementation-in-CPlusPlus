#include "lovac.h"
#include "../Igra/tabla.h"
#include <math.h>

using namespace std;

Lovac :: Lovac(const char boja) : Figura(boja,'L') {}

bool Lovac :: proveriPotez(int startY, int startX, int endY, int endX, Tabla* tabla) {
    if(abs(startX-endX) == abs(startY-endY)){
        //cout << "LOVAC\n";
        if(startY < endY && startX < endX){
            for(int i = 1; i < abs(startY - endY); i++){
                if(tabla->getPolje(startY + i, startX + i) != nullptr) return false;
                
            }
            if(tabla->getPolje(endY,endX) == nullptr || tabla->getPolje(endY, endX)->getBoja() != this->getBoja()) return true;
            return false;
        }
        else if(startY < endY && startX > endX){
            for(int i = 1; i < abs(startY - endY); i++){
                if(tabla->getPolje(startY + i, startX - i) != nullptr) return false;
            }
            if(tabla->getPolje(endY,endX) == nullptr || tabla->getPolje(endY, endX)->getBoja() != this->getBoja()) return true;
            return false;
        }
        else if(startY > endY && startX < endX){
            for(int i = 1; i < abs(startY - endY); i++){
                if(tabla->getPolje(startY - i, startX + i) != nullptr) return false;
            }
            if(tabla->getPolje(endY,endX) == nullptr || tabla->getPolje(endY, endX)->getBoja() != this->getBoja()) return true;
            return false;
        }
        else if(startY > endY && startX > endX){
            for(int i = 1; i < abs(startY - endY); i++){
                if(tabla->getPolje(startY - i, startX - i) != nullptr) return false;
            }
            if(tabla->getPolje(endY, endX) == nullptr || tabla->getPolje(endY, endX)->getBoja() != this->getBoja()) return true;
            return false;
        }
    }
    return false;
}
