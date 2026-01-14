#include "Airplane.h"
#include <stdexcept> // for std::invalid_argument

Airplane::Airplane(std::string FlightN, Schedule Sec, int Exp) {
    Seating = 60;
    FlightNo = FlightN;
    S = Sec;
    AllocateMem();
    Expense = Exp;
}

Airplane::Airplane() {
    Seating = 60;
    FlightNo = "N/A";
    Schedule A;
    S = A;
    AllocateMem();
    Expense = 0;
}

Airplane::Airplane(const Airplane& A) {
    Seating = A.Seating;
    FlightNo = A.FlightNo;
    S = A.S;
    Expense = A.Expense;
    AllocateMem();
    // Properly copy the booking array
    for (int i = 0; i < Seating; i++) {
        Booking[i] = A.Booking[i];
    }
}

Airplane::~Airplane() {
    delete[] Booking;
}

void Airplane::AllocateMem() {
    Booking = new Passenger[60];
}

void Airplane::ShowBookings() {
    for (int i = 0; i < Seating; i++) {
        std::cout << Booking[i];
    }
}

void Airplane::Change_Status(std::string s) {
    S.setStatus(s);
}

void Airplane::Change_Timing(std::string dt, std::string at) {
    try {
        if (at.size() != 5 || at[2] != ':') {
            throw std::invalid_argument("Invalid Arrival Time Format Used");
        }
        if (dt.size() != 5 || dt[2] != ':') {
            throw std::invalid_argument("Invalid Departure Time Format Used");
        }
        S.setDepartureTime(dt);
        S.setArrival(at);
    } catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }
}

std::string Airplane::getDeparture() {
    return S.getOrigin();
}

std::string Airplane::getDestination() {
    return S.getDestination();
}

void Airplane::BookSeat(Passenger P, int Seat) {
    try {
        if (Seat < 0 || Seat >= 60) {
            throw std::invalid_argument("Seat No is Invalid");
        }
        if (Booking[Seat].getname() != "N/A") {
            throw std::invalid_argument("Seat Is Booked");
        }
        Booking[Seat] = P;
        Seating--; // Only decrement if booking succeeds
    } catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }
}

void Airplane::Cancel_Bookings() {
    delete[] Booking;
    Booking = new Passenger[60];
}

void Airplane::UnBookSeat(int Seat) {
    try {
        if (Seat < 0 || Seat >= 60) {
            throw std::invalid_argument("Seat is Invalid");
        }
        if (Booking[Seat].getname() == "N/A") {
            throw std::invalid_argument("Seat is not booked");
        }
        Passenger P;
        Booking[Seat] = P;
        Seating++; // Only increment if unbooking succeeds
        std::cout << "Your Refund Is " << Expense * 0.25 << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }
}

void Airplane::ChangeSchedule(Schedule Sa) {
    try {
        if (Sa.getArrival().size() != 5 || Sa.getArrival()[2] != ':') {
            throw std::invalid_argument("Invalid Arrival Time Format Used");
        }
        if (Sa.getDepartureTime().size() != 5 || Sa.getDepartureTime()[2] != ':') {
            throw std::invalid_argument("Invalid Departure Time Format Used");
        }
        S = Sa;
    } catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }
}

void Airplane::Change_Path(std::string d, std::string a) {
    S.setOrigin(d);
    S.setDestination(a);
}

std::string Airplane::getFlightno() {
    return FlightNo;
}

void Airplane::Change_Seating(int S) {
    if (S > 0 && S <= 60) {
        Seating = S;
    } else {
        std::cout << "Either you Entered A Negative Value Or The Number exceeds Flight Max Population" << std::endl;
    }
}

std::ostream& Airplane::Display(std::ostream& out) {
    out << "FlightNo\tSeating" << std::endl;
    out << FlightNo << "\t\t" << Seating << std::endl;
    out << S << std::endl;
    out << "Expenses Rs. " << Expense;
    return out;
}

std::ostream& operator<<(std::ostream& out, Airplane S) {
    return S.Display(out);
}