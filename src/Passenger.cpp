#include "Passenger.h"

Passenger::Passenger(std::string n, std::string p, std::string us, std::string pa, bool V, std::string c, int a, Payment_Account Payment_Acc, int seat)
    : Person(n, p, us, pa) {
    VISA = V;
    CNIC = c;
    Age = a;
    Acc = Payment_Acc;
    seat_No = seat;
}

Passenger::Passenger() : Person() {
    VISA = false; // Fixed: was incorrectly set to "N/A"
    CNIC = "N/A";
    Age = 0;
    Payment_Account P;
    Acc = P;
    seat_No = 0;
}

Passenger::Passenger(const Passenger& P) : Person(P.Name, P.Phone_No, P.Username, P.Password) {
    VISA = P.VISA;
    CNIC = P.CNIC;
    Age = P.Age;
    Acc = P.Acc;
    seat_No = P.seat_No;
}

int Passenger::getseat() {
    return seat_No;
}

std::string Passenger::getname() {
    return Name;
}

std::ostream& Passenger::Display(std::ostream& out) {
    out << "PassengerName\tVISA\tAge\tCNIC" << std::endl;
    out << Name << "\t\t";
    if (VISA == 1) {
        out << "VALID" << "\t";
    } else {
        out << "INVALID" << "\t";
    }
    out << Age << "\t" << CNIC << std::endl;
    return out;
}

std::ostream& operator<<(std::ostream& out, Passenger P) {
    P.Display(out);
    return out;
}