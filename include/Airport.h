#ifndef AIRPORT_H
#define AIRPORT_H

#include "Airplane.h"
#include <string>
#include <iostream>

class Airport {
private:
    Airplane* Planes;
    std::string Name;
    int Capacity; // contain max planes standing
    bool Airport_Loc; // it will be 1 for North And 0 For South
    int capcount; // contain current planes standing

public:
    Airport(std::string n, bool Airport_L, Airplane* A, int numofplane);
    Airport();
    Airport(const Airport& A);
    ~Airport(); // Added destructor

    std::string getname();
    Airplane* getAirplane();
    int getcap();

    friend std::ostream& operator<<(std::ostream& out, Airport& A);
};

#endif // AIRPORT_H