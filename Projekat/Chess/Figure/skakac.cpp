#include "skakac.h"
#include "../Igra/tabla.h"
#include "math.h"

Skakac :: Skakac(const char boja) : Figura(boja, 'S') {}

bool Skakac :: proveriPotez(const int startY, const int startX, const int endY, const int endX, Tabla* tabla) {
    if(tabla->getPolje(endY, endX) != nullptr && tabla->getPolje(endY, endX)->getBoja() == this->getBoja()) return false;
    if(abs(startY - endY) == 1 && abs(startX - endX) == 2) return true;
    if(abs(startY - endY) == 2 && abs(startX - endX) == 1) return true;
    return false;
}
