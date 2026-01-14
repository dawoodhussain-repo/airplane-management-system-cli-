#include "Person.h"

Person::Person() {
    Name = "N/A";
    Phone_No = "N/A";
    Username = "N/A";
    Password = "N/A";
}

Person::Person(std::string n, std::string p, std::string us, std::string pa) {
    Name = n;
    Phone_No = p;
    Username = us;
    Password = pa;
}