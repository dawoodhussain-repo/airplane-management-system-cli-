#ifndef NAFS_STAFF_H
#define NAFS_STAFF_H

#include "Person.h"
#include <string>

class NAFS_Staff : public Person {
private:
    std::string Unique_Id; // Every Staff member has a unique Id which gives them Privileges of Admin Panel (Note it is 4 digits);

public:
    NAFS_Staff(std::string n, std::string p, std::string us, std::string pa, std::string ui);
    NAFS_Staff();

    std::string Getid();
    std::string getus();
    std::string getpass();
};

#endif // NAFS_STAFF_H