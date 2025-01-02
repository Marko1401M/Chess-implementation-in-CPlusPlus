#ifndef POTEZ_IZVAN_TABLE_EXCEPTION_H
#define POTEZ_IZVAN_TABLE_EXCEPTION_H

#include <exception>
using namespace std;
class PotezIzvanTableException : public exception{
    public:
        const char* what() const throw() override{
            return "Nije moguce odigrati van tabele";
        }
};

#endif