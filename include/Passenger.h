#ifndef PASSENGER_H
#define PASSENGER_H

#include "Person.h"
#include "Payment_Account.h"
#include <string>
#include <iostream>

class Passenger : public Person {
private:
    bool VISA; // 0 for rejected 1 for Approved
    std::string CNIC;
    int Age;
    int seat_No;
    Payment_Account Acc;

public:
    Passenger(std::string n, std::string p, std::string us, std::string pa, bool V, std::string c, int a, Payment_Account Payment_Acc, int seat);
    Passenger();
    Passenger(const Passenger& P);

    int getseat();
    std::string getname();
    
    // Additional getters
    std::string getCNIC() const { return CNIC; }
    int getAge() const { return Age; }
    bool getVISA() const { return VISA; }
    
    // Additional setters
    void setCNIC(const std::string& c) { CNIC = c; }
    void setAge(int a) { Age = a; }
    void setVISA(bool v) { VISA = v; }

    std::ostream& Display(std::ostream& out);
    friend std::ostream& operator<<(std::ostream& out, Passenger P);
};

#endif // PASSENGER_H