#ifndef PRAZNO_POLJE_EXCEPTION
#define PRAZNO_POLJE_EXCEPTION

#include <exception>

using namespace std;

class PraznoPoljeException : public exception{
    public:
        const char* what() const throw() override{
            return "Nije moguce odabrati prazno polje!";
        }
};

#endif