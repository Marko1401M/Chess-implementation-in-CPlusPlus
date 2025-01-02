#include "pijun.h"
#include "../Igra/tabla.h"
using namespace std;

Pijun :: Pijun(const char boja) : Figura(boja, 'P') {
    pomeren = false;
}

bool Pijun :: proveriPotez(int startX, int startY, int endX, int endY, Tabla* tabla) {
    
    if(getBoja() == 'C'){
        if(!pomeren){
            //cout << "DADADADADADA\n";
            if(startY == endY && startX == endX - 2 && tabla->getPolje(endX, endY)==nullptr && tabla->getPolje(endX-1,endY) == nullptr){
                pomeren = true;
                //cout << "LALALALALA\n";
                return true;
            }
        }
        if(startY == endY && startX == endX - 1 && tabla->getPolje(endX, endY)==nullptr){ 
            pomeren = true;
            return true;
        }
        if(startY == endY - 1 && startX == endX - 1 && tabla->getPolje(endX, endY)->getBoja() == 'B'){ 
            pomeren = true;
            return true;
        }
        if(startY == endY + 1 && startX == endX - 1 && tabla->getPolje(endX, endY)->getBoja() == 'B'){ 
            pomeren = true;
            return true;
        }
    } 
    else {
        if(!pomeren){
            //cout << "DADADADADADA\n";
            if(startY == endY && startX == endX + 2 && tabla->getPolje(endX, endY)==nullptr && tabla->getPolje(endX + 1, endY) == nullptr){
                pomeren = true;
                //cout << "PROSLO" << endl;
                return true;
            }
        }
        if(startY == endY && startX == endX + 1 && tabla->getPolje(endX, endY)==nullptr){ 
            pomeren = true;
            return true;
        }
        if(startY == endY - 1 && startX == endX + 1 && tabla->getPolje(endX, endY)->getBoja() == 'C'){ 
            pomeren = true;
            return true;
        }    
        if(startY == endY + 1 && startX == endX + 1 && tabla->getPolje(endX, endY)->getBoja() == 'C'){ 
            pomeren = true;
            return true;
        }
    }
    return false;
}
