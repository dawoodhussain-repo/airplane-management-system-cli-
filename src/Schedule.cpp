#include "Schedule.h"
#include <cstdlib> // for rand()

Schedule::Schedule() {
    Origin = "N/A";
    Destination = "N/A";
    Departure_time = "N/A";
    Arrival = "N/A";
    Traveltime = 0;
}

Schedule::Schedule(std::string d, std::string a, std::string dt, std::string at) {
    Origin = d;
    Destination = a;
    Departure_time = dt;
    Arrival = at;
    Status = "Operational";
    Traveltime = 0;
}

std::string Schedule::getOrigin() const {
    return Origin;
}

std::string Schedule::getDestination() const {
    return Destination;
}

std::string Schedule::getDepartureTime() const {
    return Departure_time;
}

std::string Schedule::getArrival() const {
    return Arrival;
}

void Schedule::setOrigin(std::string dep) {
    Origin = dep;
}

void Schedule::setStatus(std::string s) {
    Status = s;
}

void Schedule::setDestination(std::string dest) {
    Destination = dest;
}

void Schedule::setDepartureTime(std::string dep_time) {
    Departure_time = dep_time;
}

void Schedule::setArrival(std::string arr) {
    Arrival = arr;
}

std::ostream& Schedule::Display(std::ostream& out) {
    out << "DepartingCity\tDepartureTime\tArrivalCity\tArrivalTime\tStatus" << std::endl;
    out << Origin << "\t\t" << Departure_time << "\t\t" << Destination << "\t\t" << Arrival << "\t\t" << Status << std::endl;
    return out;
}

std::ostream& operator<<(std::ostream& out, Schedule S) {
    return S.Display(out);
}

void Schedule::Fly_To_Destination() {
    srand(0);

    if (Destination != "Pending" && Status == "Operational") {
        Origin = Destination;
        Destination = "PENDING";
        Departure_time = Arrival;
        Arrival = "PENDING";
        Traveltime = Traveltime + (rand() % 24);
    } else {
        std::cout << "Plane Has Flown Once and Cannot travel Till Tomorrow" << std::endl;
    }
}