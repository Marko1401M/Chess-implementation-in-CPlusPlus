#ifndef NEVALIDAN_POTEZ_EXCEPTION_H
#define NEVALIDAN_POTEZ_EXCEPTION_H

#include <exception>
using namespace std;

class NevalidanPotezException : public exception {
    public:
        const char* what() const throw() override{
            return "Potez nije validan!";
        }
};

#endif

