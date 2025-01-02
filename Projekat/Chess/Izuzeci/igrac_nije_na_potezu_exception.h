#ifndef IGRAC_NIJE_NA_POTEZU_EXCEPTION
#define IGRAC_NIJE_NA_POTEZU_EXCEPTION

#include <exception>

using namespace std;

class IgracNijeNaPotezuException : public exception{
    public:
        const char* what() const throw() override{
            return "Igrac nije na potezu!";
        }
};

#endif