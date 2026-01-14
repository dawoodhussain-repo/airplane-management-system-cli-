#include "Schedule.h"
#include "Person.h"
#include "Payment_Account.h"
#include "Passenger.h"
#include "NAFS_Staff.h"
#include "Airplane.h"
#include "Airport.h"
#include "Admin_Panel.h"
#include "Passenger_Panel.h"
#include "Utilities.h"

#include <iostream>
#include <string>
#include <conio.h> // For _getch()

int main() {
    // Create staff members
    NAFS_Staff Joe("Joe", "0301650032", "Joe@321", "12@321Dock", "4584");
    NAFS_Staff Mike("Mike", "0305331223", "Mike@112", "12@321Mark", "4582");
    NAFS_Staff Harry("Harry", "0301650034", "Harry@212", "12@321Spade", "4581");
    NAFS_Staff STAFF[] = { Joe, Mike, Harry };

    // Create payment accounts
    Payment_Account CastroAcc("1832102392112", "312", "0127");
    Passenger Castro("Castro", "0301560032", "Capti", "12E2d786@", true, "3320271705219", 25, CastroAcc, 0);

    Payment_Account JamesAcc("1832101232319", "422", "1229");
    Passenger James("James", "0301560032", "Sparrow", "12E1786@", true, "3320213205219", 37, JamesAcc, 0);

    Payment_Account WillsAcc("1832102392139", "312", "1233");
    Passenger Will("Will", "0301560032", "WillwasJAck", "Encrypt@d", true, "3320234215219", 23, WillsAcc, 0);

    Passenger Pass[] = { Castro, James, Will };

    // Create schedules
    Schedule s1("Islamabad", "Los Angeles", "12:30", "03:40");
    Schedule s2("Karachi", "Lahore", "09:00", "01:15");
    Schedule s3("Peshawar", "Karachi", "08:45", "10:30");
    Schedule s4("Islamabad", "Las Vegas", "11:30", "12:45");
    Schedule s5("Lahore", "Atlanta", "02:15", "05:30");
    Schedule s6("Islamabad", "Peshawar", "12:30", "03:40");
    Schedule s7("Karachi", "Lahore", "02:00", "11:15");
    Schedule s8("Peshawar", "Albama", "06:15", "11:20");
    Schedule s9("Islamabad", "Quetta", "11:30", "02:55");
    Schedule s10("Lahore", "Quetta", "02:15", "06:30");

    // Create airplanes
    Airplane a1("SUA1234", s1, 54000);
    Airplane a2("SAA2345", s2, 12000);
    Airplane a3("SDL3456", s3, 32040);
    Airplane a4("SWN4567", s4, 12420);
    Airplane a5("SB65678", s5, 12200);
    Airplane a6("NUA1234", s6, 23000);
    Airplane a7("NAA2345", s7, 120000);
    Airplane a8("NDL3456", s8, 32040);
    Airplane a9("NWN4567", s9, 12420);
    Airplane a10("NB65678", s10, 12200);

    // Create airports
    Airplane planes1[] = { a1, a2, a3, a4, a5 };
    Airport airport1("Islamabad", true, planes1, 5);
    Airplane planes2[] = { a2, a3, a4, a5, a1 };
    Airport airport2("Lahore", true, planes2, 5);
    Airplane planes3[] = { a3, a4, a5, a1, a2 };
    Airport airport3("Karachi", true, planes3, 5);
    Airplane planes4[] = { a4, a5, a1, a2, a3 };
    Airport airport4("Quetta", true, planes4, 5);
    Airplane planes5[] = { a5, a1, a2, a3, a4 };
    Airport airport5("Peshawar", true, planes5, 5);
    Airplane planes6[] = { a6, a7, a8, a9, a10 };
    Airport airport6("Islamabad", false, planes1, 5);
    Airplane planes7[] = { a8, a6, a7, a10, a9 };
    Airport airport7("Lahore", false, planes2, 5);
    Airplane planes8[] = { a8, a9, a10, a6, a7 };
    Airport airport8("Karachi", false, planes3, 5);
    Airplane planes9[] = { a6, a7, a8, a9, a10 };
    Airport airport9("Quetta", false, planes4, 5);
    Airplane planes10[] = { a10, a7, a6, a8, a9 };
    Airport airport10("Peshawar", false, planes5, 5);

    Airport Airs[] = { airport1, airport2, airport3, airport4, airport5, airport6, airport7, airport8, airport9, airport10 };

    Admin_Panel ADMINS(STAFF, 3, Airs, 10);
    Passeger_Panel PASSENERS(Pass, 3, Airs, 10);

    std::string username, pass, name;
    std::string depart, arrival, departtime, arrivaltime;
    std::string newusername, newpass, newpass1;
    Passenger tempP;
    char ch = ' ';
    int res;
    int fno;

    std::cout << "----------------------NUCES AIRLINE---------------------------" << std::endl;

START:
    pass = "";
    newpass = "";
    std::cout << "Please Select Your Correct Designation For Best Experience" << std::endl;
    std::cout << "1. Admin Member" << std::endl;
    std::cout << "2. Passenger" << std::endl;
    std::cout << "3. New To NAFS Register Today" << std::endl;
    std::cout << "4. See Ongoing Flights" << std::endl;
    std::cout << "5. More About Us" << std::endl;
    std::cout << "6. Exit" << std::endl;

    int n;
    std::cin >> n;

    switch (n) {
    case 1: {
        std::cout << "Enter Your Username" << std::endl;
        std::getline(std::cin, username);
        std::getline(std::cin, username);
        std::cout << "Enter Your Password" << std::endl;
        ch = _getch();
        while (true) {
            if (ch == 13) break;
            pass.push_back(ch);
            std::cout << "*";
            ch = _getch();
        }
        std::cout << std::endl;

        if (ADMINS.checkMember(username, pass) == true) {
        ADMINMENU:
            pass = "";
            newpass = "";
            std::cout << "-------------------WELCOME-------------------" << std::endl;
            std::cout << "1. Restrict Passengers" << std::endl;
            std::cout << "2. Change Schedule " << std::endl;
            std::cout << "3. Change Path/Routes Of Flight" << std::endl;
            std::cout << "4. Update Inquiry" << std::endl;
            std::cout << "5. Display Airlines" << std::endl;
            std::cout << "6. Halt Flight" << std::endl;
            std::cout << "7. Cancel Flight" << std::endl;
            std::cout << "8. Return" << std::endl;
            std::cout << "9. exit" << std::endl;
            std::cin >> n;

            switch (n) {
            case 1: {
                try {
                    std::cout << "Enter The Airport Name " << std::endl;
                    std::cin >> name;
                    if (name != "Islamabad" && name != "Lahore" && name != "Peshawar" && name != "Quetta" && name != "Karachi") {
                        std::cout << "Non-Existing Airport" << std::endl;
                        goto ADMINMENU;
                    }
                    std::cout << "Enter The Flight No of Plane You Wish To Restrict" << std::endl;
                    std::cin >> fno;
                    fno--;
                    if (fno > 4) { // Fixed: was checking > 5, but arrays are 0-4
                        std::cout << "Non-Existant Flight" << std::endl;
                        goto ADMINMENU;
                    }
                    std::cout << "Enter the restricted seats" << std::endl;
                    std::cin >> res;
                    ADMINS.RestrictAirplane(name, fno, res);
                } catch (const std::exception& e) {
                    std::cout << e.what() << std::endl;
                    goto ADMINMENU;
                }
                goto ADMINMENU;
            }
            case 2: {
                std::cout << "Enter The Airport Name " << std::endl;
                std::cin >> name;
                if (name != "Islamabad" && name != "Lahore" && name != "Peshawar" && name != "Quetta" && name != "Karachi") {
                    std::cout << "Non-Existing Airport" << std::endl;
                    goto ADMINMENU;
                }
                std::cout << "Enter The Flight No of Plane You Wish To Restrict" << std::endl;
                std::cin >> fno;
                fno--;
                if (fno > 4) {
                    std::cout << "Non-Existant Flight" << std::endl;
                    goto ADMINMENU;
                }
                std::cout << "Enter the The New Schedule Departure Time" << std::endl;
                std::cin >> departtime;
                std::cout << "Enter the The New Schedule Arrival Time" << std::endl;
                std::cin >> arrivaltime;
                ADMINS.Change_Schedule(name, fno, departtime, arrivaltime);
                goto ADMINMENU;
            }
            case 3: {
                std::cout << "Enter The Airport Name " << std::endl;
                std::cin >> name;
                if (name != "Islamabad" && name != "Lahore" && name != "Peshawar" && name != "Quetta" && name != "Karachi") {
                    std::cout << "Non-Existing Airport" << std::endl;
                    goto ADMINMENU;
                }
                std::cout << "Enter The Flight No of Plane You Wish To Restrict" << std::endl;
                std::cin >> fno;
                fno--;
                if (fno > 4) {
                    std::cout << "Non-Existant Flight" << std::endl;
                    goto ADMINMENU;
                }
                std::cout << "Enter the The New Schedule Departure Place" << std::endl;
                std::cin >> depart;
                std::cout << "Enter the The New Schedule Destination" << std::endl;
                std::cin >> arrival;
                ADMINS.Change_Path(name, fno, depart, arrival);
                goto ADMINMENU;
            }
            case 4: {
                std::cout << "Enter The Airport Name " << std::endl;
                std::cin >> name;
                if (name != "Islamabad" && name != "Lahore" && name != "Peshawar" && name != "Quetta" && name != "Karachi") {
                    std::cout << "Non-Existing Airport" << std::endl;
                    goto ADMINMENU;
                }
                std::cout << "Enter The Flight No of Plane You Wish To Restrict" << std::endl;
                std::cin >> fno;
                fno--;
                if (fno > 4) {
                    std::cout << "Non-Existant Flight" << std::endl;
                    goto ADMINMENU;
                }
                std::cout << "Enter the The New Schedule Departure Time" << std::endl;
                std::cin >> departtime;
                std::cout << "Enter the The New Schedule Arrival Time" << std::endl;
                std::cin >> arrivaltime;
                std::cout << "Enter the The New Schedule Departure Place" << std::endl;
                std::cin >> depart;
                std::cout << "Enter the The New Schedule Destination" << std::endl;
                std::cin >> arrival;
                ADMINS.Change_Path(name, fno, depart, arrival);
                ADMINS.Change_Schedule(name, fno, departtime, arrivaltime);
                goto ADMINMENU;
            }
            case 5: {
                ADMINS.DisplayFlights();
                goto ADMINMENU;
            }
            case 6: {
                std::cout << "Enter The Airport Name " << std::endl;
                std::cin >> name;
                if (name != "Islamabad" && name != "Lahore" && name != "Peshawar" && name != "Quetta" && name != "Karachi") {
                    std::cout << "Non-Existing Airport" << std::endl;
                    goto ADMINMENU;
                }
                std::cout << "Enter The Flight No of Plane You Wish To Restrict" << std::endl;
                std::cin >> fno;
                fno--;
                if (fno > 4) {
                    std::cout << "Non-Existant Flight" << std::endl;
                    goto ADMINMENU;
                }
                ADMINS.Halt_Flight(name, fno);
                goto ADMINMENU;
            }
            case 7: {
                std::cout << "Enter The Airport Name " << std::endl;
                std::cin >> name;
                if (name != "Islamabad" && name != "Lahore" && name != "Peshawar" && name != "Quetta" && name != "Karachi") {
                    std::cout << "Non-Existing Airport" << std::endl;
                    goto ADMINMENU;
                }
                std::cout << "Enter The Flight No of Plane You Wish To Restrict" << std::endl;
                std::cin >> fno;
                fno--;
                if (fno > 4) {
                    std::cout << "Non-Existant Flight" << std::endl;
                    goto ADMINMENU;
                }
                ADMINS.Cancel_Flight(name, fno);
                goto ADMINMENU;
            }
            case 8: {
                goto START;
            }
            case 9: {
                exit(0);
            }
            default: {
                std::cout << "INVALID SELECTION" << std::endl;
                goto ADMINMENU;
            }
            }
        } else {
            std::cout << "You are Not a Registered Member Please Proceed Back" << std::endl;
        }
        goto START;
    }
    case 2: {
        std::cout << "Enter Your Username" << std::endl;
        std::getline(std::cin, username);
        std::getline(std::cin, username);
        std::cout << "Enter Your Password" << std::endl;
        ch = _getch();
        while (true) {
            if (ch == 13) break;
            pass.push_back(ch);
            std::cout << "*";
            ch = _getch();
        }

        if (PASSENERS.Check_Passenger(username, pass) == true) {
        USERPANEL:
            std::cout << std::endl;
            std::cout << "1. Book Flight" << std::endl;
            std::cout << "2. View Flight Details" << std::endl;
            std::cout << "3. Cancel Flight" << std::endl;
            std::cout << "4. Reset Username" << std::endl;
            std::cout << "5. Reset Password" << std::endl;
            std::cout << "6. Return" << std::endl;
            std::cout << "7. Exit" << std::endl;
            std::cin >> n;

            switch (n) {
            case 1: {
                std::cout << "Enter Your Origin" << std::endl;
                std::getline(std::cin, depart);
                std::getline(std::cin, depart);
                std::cout << "Enter Your Destination" << std::endl;
                std::getline(std::cin, arrival);
                std::cout << "Enter Seat No You Wish To Book" << std::endl;
                std::cin >> fno;
                if (fno > 59 || fno < 0) {
                    std::cout << "Invalid Seat Selected" << std::endl;
                    goto USERPANEL;
                }
                tempP = PASSENERS.SearchPassenger(username, pass);
                if (PASSENERS.BookSeat(depart, arrival, fno, tempP) == true) {
                    std::cout << "Booking Successful" << std::endl;
                } else {
                    std::cout << "Booking Failed" << std::endl;
                }
                goto START;
            }
            case 2: {
                ADMINS.DisplayFlights();
                goto USERPANEL;
            }
            case 3: {
                std::cout << "Please Enter Some Details for unbooking firstly tell your Origin of Flight" << std::endl;
                std::getline(std::cin, depart);
                std::getline(std::cin, depart);
                std::cout << "Enter Your Destination" << std::endl;
                std::getline(std::cin, arrival);
                std::cout << "Enter Seat No You Wish To UnBook" << std::endl;
                std::cin >> fno;
                if (fno > 59 || fno < 0) {
                    std::cout << "Invalid Seat Selected" << std::endl;
                    goto USERPANEL;
                }
                if (PASSENERS.UnBookSeat(depart, arrival, fno) == true) {
                    std::cout << "UnBooking Successful" << std::endl;
                } else {
                    std::cout << "UnBooking Failed" << std::endl;
                }
                goto START;
            }
            case 4: {
                std::cout << "Enter Your new Username" << std::endl;
                std::getline(std::cin, newusername);
                std::getline(std::cin, newusername);
                if (PASSENERS.UpdateUsername(username, pass, newusername) == true) {
                    std::cout << "Updated Successfully" << std::endl;
                } else {
                    std::cout << "Updation Unsuccessful" << std::endl;
                }
                goto USERPANEL;
            }
            case 5: {
                std::cout << "Enter Your new Password" << std::endl;
                try {
                    ch = _getch();
                    while (true) {
                        if (ch == 13) break;
                        newpass.push_back(ch);
                        std::cout << "*";
                        ch = _getch();
                    }
                    std::cout << std::endl;
                    std::cout << "Re-Enter Your Password" << std::endl;
                    ch = _getch();
                    while (true) {
                        if (ch == 13) break;
                        newpass1.push_back(ch);
                        std::cout << "*";
                        ch = _getch();
                    }
                    std::cout << std::endl;
                    if (newpass != newpass1) {
                        throw std::invalid_argument("Your Password Does Not Match The one you entered");
                    }
                    if (newpass.empty() || newpass.length() < 8) {
                        throw std::invalid_argument("Password Must be atleast 8 characters");
                    }

                    bool uc = false, lc = false, num = false, sc = false;
                    for (char c : newpass) {
                        if (std::isupper(c)) uc = true;
                        if (std::islower(c)) lc = true;
                        if ((c >= 32 && c <= 47) || (c >= 58 && c <= 64) || (c >= 91 && c <= 96) || (c >= 123 && c <= 126)) sc = true;
                        if (c >= 48 && c <= 57) num = true;
                    }

                    if (!sc) {
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
                } catch (const std::invalid_argument& e) {
                    std::cout << e.what() << std::endl;
                    goto USERPANEL;
                }

                if (PASSENERS.UpdatePass(username, pass, newpass) == true) {
                    std::cout << "Updated Successfully" << std::endl;
                } else {
                    std::cout << "Updation Unsuccessful" << std::endl;
                }
                goto USERPANEL;
            }
            case 6: {
                goto START;
            }
            default: {
                std::cout << "Invalid Selection Please Select According to Number" << std::endl;
                goto USERPANEL;
            }
            }
        } else {
            std::cout << "You are Not a Registered Passenger But You can Always Register :)" << std::endl;
        }
        goto START;
    }
    case 3: {
        PASSENERS.Register_Passenger();
        goto START;
    }
    case 4: {
        ADMINS.DisplayFlights();
        goto START;
    }
    case 5: {
        std::cout << "NUCES Airline System is a newly made Airline Management System created by our finest Staff and Developers to Provide Ease of Access to our Dear Passengers. We prefer Quality over Quantity Hence we have limited Airlines But Top Notch. Moreever we provide services over 32 countries and 5 cities of Pakistan That are\n Lahore\nIslamabad\nQuetta\nPeshawar\nKarachi" << std::endl;
        goto START;
    }
    case 6: {
        exit(0);
    }
    default: {
        std::cout << "Invalid Selection please Try Again" << std::endl;
        goto START;
    }
    }

    return 0;
}