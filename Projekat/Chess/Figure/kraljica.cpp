#include "kraljica.h"
#include "../Igra/tabla.h"

Kraljica :: Kraljica(const char boja) : Figura(boja, 'Q'){}

bool Kraljica :: proveriPotez(int startY, int startX, int endY, int endX, Tabla* tabla) {
    if(endY > startY && startX == endX){
        for(int i = startY + 1; i < endY; i++){
            if(tabla->getPolje(i,startX) != nullptr) return false;
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
    else if(abs(startX-endX) == abs(startY-endY)){
        //cout << "LOVAC\n";
        //cout << startX - endX << endl;
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
