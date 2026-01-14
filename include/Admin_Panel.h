#ifndef ADMIN_PANEL_H
#define ADMIN_PANEL_H

#include "NAFS_Staff.h"
#include "Airport.h"
#include <string>

class Admin_Panel {
private:
    Airport* Airports; // contains all airport details to be accessed by Admins
    int numofAirport;
    NAFS_Staff* Active_Staff; // it contains The Staff that are registered in NAFS system
    int numofStaff;

public:
    Admin_Panel();
    Admin_Panel(NAFS_Staff* A, int size, Airport* Air, int NA);
    ~Admin_Panel(); // Added destructor

    void RestrictAirplane(std::string name, int fno, int size);
    void Cancel_Flight(std::string name, int j);
    void Halt_Flight(std::string name, int j);
    bool checkMember(std::string us, std::string pas);
    void Change_Schedule(std::string name, int fno, std::string departtime, std::string arrivetime);
    void Change_Path(std::string name, int fno, std::string Origin, std::string Destiny);
    void DisplayFlights();
};

#endif // ADMIN_PANEL_H