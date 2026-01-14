#include "Passenger_Panel.h"
#include <conio.h> // For _getch()
#include <stdexcept> // For exceptions

Passeger_Panel::Passeger_Panel() {
    Airports = nullptr;
    numofairports = 0;
}

Passeger_Panel::Passeger_Panel(Passenger* P, int si, Airport* A, int NA) {
    // Properly copy passengers
    for (int i = 0; i < si; i++) {
        PassengerList.push_back(P[i]);
    }
    Airports = new Airport[NA];
    for (int i = 0; i < NA; i++) {
        Airports[i] = A[i];
    }
    numofairports = NA;
}

Passeger_Panel::~Passeger_Panel() {
    delete[] Airports;
}

bool Passeger_Panel::Check_Passenger(std::string username, std::string pass) {
    for (const auto& passenger : PassengerList) {
        if (username == passenger.getUsername() && pass == passenger.getPassword()) {
            return true;
        }
    }
    return false;
}

Passenger Passeger_Panel::SearchPassenger(std::string us, std::string pass) {
    for (const auto& passenger : PassengerList) {
        if (passenger.getUsername() == us && passenger.getPassword() == pass) {
            return passenger;
        }
    }
    return Passenger(); // Return default passenger if not found
}

bool Passeger_Panel::BookSeat(std::string depart, std::string arrival, int no, Passenger P) {
    for (int i = 0; i < numofairports; i++) {
        for (int j = 0; j < 5; j++) {
            if (Airports[i].getAirplane()[j].getDeparture() == depart &&
                Airports[i].getAirplane()[j].getDestination() == arrival) {
                Airports[i].getAirplane()[j].BookSeat(P, no);
                return true;
            }
        }
    }
    return false;
}

bool Passeger_Panel::UpdateUsername(std::string username, std::string pass, std::string newusername) {
    for (auto& passenger : PassengerList) {
        if (passenger.getUsername() == username && passenger.getPassword() == pass) {
            passenger.setUsername(newusername);
            return true;
        }
    }
    return false;
}

bool Passeger_Panel::UpdatePass(std::string username, std::string pass, std::string newpass) {
    for (auto& passenger : PassengerList) {
        if (passenger.getUsername() == username && passenger.getPassword() == pass) {
            passenger.setPassword(newpass);
            return true;
        }
    }
    return false;
}

bool Passeger_Panel::UnBookSeat(std::string depart, std::string arrival, int no) {
    for (int i = 0; i < numofairports; i++) {
        for (int j = 0; j < 5; j++) {
            if (Airports[i].getAirplane()[j].getDeparture() == depart &&
                Airports[i].getAirplane()[j].getDestination() == arrival) {
                Airports[i].getAirplane()[j].UnBookSeat(no);
                return true;
            }
        }
    }
    return false;
}

void Passeger_Panel::Register_Passenger() {
    bool num = false, uc = false, lc = false, sc = false;
    std::string acc, cvv, exp;
    std::string usern, password, phno, Name, CNIC, pass;
    int Age;
    char ch;

Begining:
    try {
        std::cout << "Enter Your Name" << std::endl;
        std::getline(std::cin, Name);
        std::getline(std::cin, Name); // Extra getline to handle leftover newline
        if (Name.empty()) {
            throw std::invalid_argument("Name Cannot Be Empty");
        }

        std::cout << "Enter Your Username" << std::endl;
        std::getline(std::cin, usern);
        if (usern.empty()) {
            throw std::invalid_argument("UserName Cannot Be Empty");
        }

        std::cout << "Enter Your Password" << std::endl;
        ch = _getch();
        while (true) {
            if (ch == 13) break; // Enter key
            password.push_back(ch);
            std::cout << "*";
            ch = _getch();
        }
        std::cout << std::endl;

        std::cout << "Re-Enter Your Password" << std::endl;
        ch = _getch();
        while (true) {
            if (ch == 13) break;
            pass.push_back(ch);
            std::cout << "*";
            ch = _getch();
        }
        std::cout << std::endl;

        if (password != pass) {
            throw std::invalid_argument("Your Password Does Not Match The one you entered");
        }
        if (password.empty() || password.length() < 8) {
            throw std::invalid_argument("Password Must be atleast 8 characters");
        }

        // Check password requirements
        for (char c : password) {
            if (std::isupper(c)) uc = true;
            if (std::islower(c)) lc = true;
            if ((c >= 32 && c <= 47) || (c >= 58 && c <= 64) || (c >= 91 && c <= 96) || (c >= 123 && c <= 126)) sc = true;
            if (c >= 48 && c <= 57) num = true; // Fixed: was checking wrong range
        }

        if (!sc) { // Fixed: was using assignment instead of comparison
            throw std::invalid_argument("Password Must contain at least 1 special character");
        }
        if (!lc) {
            throw std::invalid_argument("Password Must contain at least 1 lowercase letter");
        }
        if (!uc) {
            throw std::invalid_argument("Password Must contain at least 1 uppercase letter");
        }
        if (!num) {
            throw std::invalid_argument("Password Must contain at least 1 number");
        }

        std::cout << "Enter Your CNIC" << std::endl;
        std::cin >> CNIC;
        if (CNIC.length() != 13) {
            throw std::invalid_argument("Invalid CNIC");
        }

        // Check for duplicate CNIC
        for (const auto& passenger : PassengerList) {
            if (passenger.getCNIC() == CNIC) {
                throw std::invalid_argument("CNIC is already registered");
            }
        }

        std::cout << "Enter Your phone number" << std::endl;
        std::cin >> phno;
        if (phno.empty() || phno.length() != 11) {
            throw std::invalid_argument("Phone Number Must have 11 Digits");
        }

        std::cout << "Enter Your Age" << std::endl;
        std::cin >> Age;
        if (Age <= 0) {
            throw std::invalid_argument("Not a Valid Age");
        }

        std::cout << "-----------------PAYMENT INFO----------------" << std::endl;
        std::cout << "Enter Account Number" << std::endl;
        std::cin >> acc;
        if (acc.length() != 14) {
            throw std::invalid_argument("Account Number is Not Valid");
        }

        std::cout << "Enter CVV" << std::endl;
        std::cin >> cvv;
        if (cvv.length() != 3) {
            throw std::invalid_argument("CVV is Incorrect");
        }

        std::cout << "Enter Expiry Date (Format: MMYY )" << std::endl;
        std::cin >> exp;
        if (exp.length() != 4) {
            throw std::invalid_argument("Please Use Correct format for expiry date");
        }

    } catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
        std::cout << "You are Being redirected to Start" << std::endl;
        goto Begining;
    }

    Payment_Account P(acc, cvv, exp);
    Passenger newPassenger(Name, phno, usern, password, true, CNIC, Age, P, 0);
    PassengerList.push_back(newPassenger);
}

std::ostream& Passeger_Panel::Display(std::ostream& out) {
    for (const auto& passenger : PassengerList) {
        out << passenger;
    }
    return out;
}

std::ostream& operator<<(std::ostream& out, Passeger_Panel& P) {
    return P.Display(out);
}