#include "NAFS_Staff.h"

NAFS_Staff::NAFS_Staff(std::string n, std::string p, std::string us, std::string pa, std::string ui)
    : Person(n, p, us, pa) {
    Unique_Id = ui;
}

NAFS_Staff::NAFS_Staff() : Person() {
    Unique_Id = "N/A";
}

std::string NAFS_Staff::Getid() {
    return Unique_Id;
}

std::string NAFS_Staff::getus() {
    return Username;
}

std::string NAFS_Staff::getpass() {
    return Password;
}