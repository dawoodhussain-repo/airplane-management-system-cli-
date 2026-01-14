#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
protected:
    std::string Name;
    std::string Phone_No;
    std::string Username;
    std::string Password;

public:
    Person();
    Person(std::string n, std::string p, std::string us, std::string pa);

    // Getters can be added if needed
};

#endif // PERSON_H