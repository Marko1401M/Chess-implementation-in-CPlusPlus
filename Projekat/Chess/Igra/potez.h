#ifndef POTEZ_H
#define POTEZ_H

#include <string>

using namespace std;

class Potez{
    public:
            Potez(const char, const int, const char, const int, const int);
            string getPotez() const;
            friend ostream& operator <<(ostream&, Potez*);
    private:
                char startY, endY;
                int startX, endX;
                int redniBroj;

};

#endif