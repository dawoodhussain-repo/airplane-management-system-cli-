#include "Airport.h"

Airport::Airport(std::string n, bool Airport_L, Airplane* A, int numofplane) {
    Name = n;
    Airport_Loc = Airport_L;
    capcount = numofplane;
    Capacity = 5;
    Planes = new Airplane[Capacity];
    // Properly copy the airplanes
    for (int i = 0; i < numofplane && i < Capacity; i++) {
        Planes[i] = A[i];
    }
}

Airport::Airport() {
    Name = "N/A";
    Airport_Loc = false;
    Capacity = 5;
    Planes = new Airplane[Capacity];
    capcount = 0;
}

Airport::Airport(const Airport& A) {
    Planes = new Airplane[A.Capacity];
    Name = A.Name;
    Airport_Loc = A.Airport_Loc;
    Capacity = A.Capacity;
    // Properly copy the airplanes
    for (int i = 0; i < Capacity; i++) {
        Planes[i] = A.Planes[i];
    }
    capcount = A.capcount;
}

Airport::~Airport() {
    delete[] Planes;
}

std::string Airport::getname() {
    return Name;
}

Airplane* Airport::getAirplane() {
    return Planes;
}

int Airport::getcap() {
    return capcount;
}

std::ostream& operator<<(std::ostream& out, Airport& A) {
    out << "Name\t\tAvailableFlights\tAirport_Location" << std::endl;
    out << A.Name << "\t" << A.capcount << "\t\t\t";
    if (A.Airport_Loc == 0) {
        out << "South" << std::endl;
    } else {
        out << "North" << std::endl;
    }
    out << "------------------------------------------" << std::endl;
    for (int i = 0; i < A.capcount; i++) {
        out << "***************************" << std::endl;
        out << A.Planes[i];
    }
    return out;
}