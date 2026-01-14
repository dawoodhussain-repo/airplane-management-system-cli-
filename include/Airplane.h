#ifndef AIRPLANE_H
#define AIRPLANE_H

#include "Schedule.h"
#include "Passenger.h"
#include <string>
#include <iostream>

class Airplane {
private:
    int Seating; // contains details of seats 0-50 are economy and 50-60 are Business
    Passenger* Booking; // contains detail of passenger and their seat No
    std::string FlightNo;
    Schedule S; // Contains Flight Take Off Times
    int Expense;

public:
    Airplane(std::string FlightN, Schedule Sec, int Exp);
    Airplane();
    Airplane(const Airplane& A);
    ~Airplane(); // Added destructor for proper memory management

    void ShowBookings();
    void Change_Status(std::string s);
    void Change_Timing(std::string dt, std::string at);
    std::string getDeparture();
    std::string getDestination();
    void BookSeat(Passenger P, int Seat);
    void Cancel_Bookings();
    void UnBookSeat(int Seat);
    void ChangeSchedule(Schedule Sa);
    void Change_Path(std::string d, std::string a);
    std::string getFlightno();
    void Change_Seating(int S);
    std::ostream& Display(std::ostream& out);
    friend std::ostream& operator<<(std::ostream& out, Airplane S);

private:
    void AllocateMem();
};

#endif // AIRPLANE_H