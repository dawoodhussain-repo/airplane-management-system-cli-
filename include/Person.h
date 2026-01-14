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

    // Getters
    std::string getUsername() const { return Username; }
    std::string getPassword() const { return Password; }
    std::string getName() const { return Name; }
    std::string getPhoneNo() const { return Phone_No; }
    
    // Setters
    void setUsername(const std::string& u) { Username = u; }
    void setPassword(const std::string& p) { Password = p; }
    void setName(const std::string& n) { Name = n; }
    void setPhoneNo(const std::string& p) { Phone_No = p; }
};

#endif // PERSON_H