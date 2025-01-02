#ifndef FIGURA_H
#define FIGURA_H

#include <iostream> 

using namespace std;

class Tabla;


class Figura{
    public:
        Figura(const char boja, const char tip);
        virtual bool proveriPotez(const int , const int , const int , const int endY, Tabla*) = 0;
        char getBoja() const;
        char getTip() const;
        friend ostream& operator <<(ostream&, Figura*);
    private:
        char boja;
        char tip;
};

#endif