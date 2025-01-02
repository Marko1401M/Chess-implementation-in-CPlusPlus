#include "kralj.h"
#include "../Igra/tabla.h"

Kralj :: Kralj(const char boja) : Figura(boja, 'K') {}

bool Kralj :: proveriPotez(const int startY, const int startX, const int endY, const int endX, Tabla* tabla) {
    if(abs(startY - endY)<= 1 && abs(startX - endX) <= 1 && (tabla->getPolje(endY, endX) == nullptr || tabla->getPolje(endY, endX)->getBoja() != this->getBoja())) return true;
    return false;
}
