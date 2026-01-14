#include "Admin_Panel.h"

Admin_Panel::Admin_Panel() {
    Active_Staff = nullptr;
    numofStaff = 0;
    numofAirport = 0;
    Airports = nullptr;
}

Admin_Panel::Admin_Panel(NAFS_Staff* A, int size, Airport* Air, int NA) {
    Active_Staff = new NAFS_Staff[size];
    numofStaff = size;
    for (int i = 0; i < size; i++) {
        Active_Staff[i] = A[i];
    }
    numofAirport = NA;
    Airports = new Airport[NA];
    for (int i = 0; i < NA; i++) {
        Airports[i] = Air[i];
    }
}

Admin_Panel::~Admin_Panel() {
    delete[] Active_Staff;
    delete[] Airports;
}

void Admin_Panel::RestrictAirplane(std::string name, int fno, int size) {
    for (int i = 0; i < numofAirport; i++) {
        if (Airports[i].getname() == name) {
            Airports[i].getAirplane()[fno].Change_Seating(size);
        }
    }
}

void Admin_Panel::Cancel_Flight(std::string name, int j) {
    for (int i = 0; i < numofAirport; i++) {
        if (Airports[i].getname() == name) {
            Airports[i].getAirplane()[j].Change_Status("Cancelled");
            Airports[i].getAirplane()[j].Cancel_Bookings();
            Airports[i].getAirplane()[j].Change_Timing("--:--", "--:--");
            Airports[i].getAirplane()[j].Change_Path("--:--", "--:--");
        }
    }
}

void Admin_Panel::Halt_Flight(std::string name, int j) {
    for (int i = 0; i < numofAirport; i++) {
        if (Airports[i].getname() == name) {
            Airports[i].getAirplane()[j].Change_Status("Halted");
        }
    }
}

bool Admin_Panel::checkMember(std::string us, std::string pas) {
    for (int i = 0; i < numofStaff; i++) {
        if (Active_Staff[i].getus() == us && Active_Staff[i].getpass() == pas) {
            return true;
        }
    }
    return false;
}

void Admin_Panel::Change_Schedule(std::string name, int fno, std::string departtime, std::string arrivetime) {
    for (int i = 0; i < numofAirport; i++) {
        if (Airports[i].getname() == name) {
            Airports[i].getAirplane()[fno].Change_Timing(departtime, arrivetime);
        }
    }
}

void Admin_Panel::Change_Path(std::string name, int fno, std::string Origin, std::string Destiny) {
    for (int i = 0; i < numofAirport; i++) {
        if (Airports[i].getname() == name) {
            Airports[i].getAirplane()[fno].Change_Path(Origin, Destiny);
        }
    }
}

void Admin_Panel::DisplayFlights() {
    for (int i = 0; i < numofAirport; i++) {
        std::cout << Airports[i];
    }
}