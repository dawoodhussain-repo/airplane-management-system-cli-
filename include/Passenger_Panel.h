#ifndef PASSENGER_PANEL_H
#define PASSENGER_PANEL_H

#include "Passenger.h"
#include "Airport.h"
#include <string>
#include <iostream>
#include <vector> // For dynamic arrays

class Passeger_Panel {
private:
    std::vector<Passenger> PassengerList; // Changed to vector for better memory management
    Airport* Airports; // to let Passengers Book Flights
    int numofairports;

public:
    Passeger_Panel();
    Passeger_Panel(Passenger* P, int si, Airport* A, int NA);
    ~Passeger_Panel(); // Added destructor

    bool Check_Passenger(std::string username, std::string pass);
    Passenger SearchPassenger(std::string us, std::string pass);
    bool BookSeat(std::string depart, std::string arrival, int no, Passenger P);
    bool UpdateUsername(std::string username, std::string pass, std::string newusername);
    bool UpdatePass(std::string username, std::string pass, std::string newpass);
    bool UnBookSeat(std::string depart, std::string arrival, int no);
    void Register_Passenger();
    std::ostream& Display(std::ostream& out);
    friend std::ostream& operator<<(std::ostream& out, Passeger_Panel& P);
};

#endif // PASSENGER_PANEL_H