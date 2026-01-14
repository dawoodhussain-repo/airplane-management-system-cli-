#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <string>
#include <iostream>

class Schedule {
private:
    std::string Origin;
    std::string Destination;
    std::string Departure_time;
    std::string Arrival;
    std::string Status;
    int Traveltime; // Contains Travel Hours of a Airplane

public:
    Schedule();
    Schedule(std::string d, std::string a, std::string dt, std::string at);

    std::string getOrigin() const;
    std::string getDestination() const;
    std::string getDepartureTime() const;
    std::string getArrival() const;

    void setOrigin(std::string dep);
    void setStatus(std::string s);
    void setDestination(std::string dest);
    void setDepartureTime(std::string dep_time);
    void setArrival(std::string arr);

    std::ostream& Display(std::ostream& out);
    friend std::ostream& operator<<(std::ostream& out, Schedule S);

    void Fly_To_Destination();
};

#endif // SCHEDULE_H