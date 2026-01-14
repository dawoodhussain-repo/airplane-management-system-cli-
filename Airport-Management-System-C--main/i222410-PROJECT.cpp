// i222410-DAWOOD HUSSAIN
#include <iostream>
#include <string>
#include<conio.h>
using namespace std;
class Passenger;
class Schedule
{
private:
    string Origin;
    string Destination;
    string Departure_time;
    string Arrival;
    string Status;
    int Traveltime; // COntains Travel Hours of a Airplane
public:
    Schedule()
    {
        Origin = "N/A";
        Destination = "N/A";
        Departure_time = "N/A";
        Arrival = "N/A";
        Traveltime = 0;
    }
    Schedule(string d, string a, string dt, string at)
    {
        Origin = d;
        Destination = a;
        Departure_time = dt;
        Arrival = at;
        Status = "Operational";
        Traveltime = 0;
    }
    string getOrigin() const {
        return Origin;
    }

    string getDestination() const {
        return Destination;
    }

    string getDepartureTime() const {
        return Departure_time;
    }

    string getArrival() const {
        return Arrival;
    }

    void setOrigin(string dep) {
        Origin = dep;
    }
    void setStatus(string s) {
        Status = s;
    }
    void setDestination(string dest) {
        Destination = dest;
    }

    void setDepartureTime(string dep_time) {
        Departure_time = dep_time;
    }

    void setArrival(string arr) {
        Arrival = arr;
    }

    ostream& Display(ostream& out)
    {
        out << "DepartingCity\tDepartureTime\tArrivalCity\tArrivalTime\tStatus" << endl;
        out << Origin << "\t\t" << Departure_time << "\t\t" << Destination << "\t\t" << Arrival <<"\t\t"<<Status << endl;
        return out;
    }
    friend ostream& operator<<(ostream& out, Schedule S)
    {
        return S.Display(out);
    }
    void Fly_To_Destination()
    {
        srand(0);
  
        if (Destination != "Pending" && Status=="Operational")
        {
            Origin = Destination;
            Destination = "PENDING";
            Departure_time = Arrival;
            Arrival = "PENDING";
            Traveltime = Traveltime + (rand() % 24);
        }
        else
        {
            cout << "Plane Has Flewn Once and Cannot travel Till Tommorrow" << endl;
        }
    }
    
};
class Airplane {
private:
    int Seating; // contains details of seats 0-50 are economy and 50-60 are Business
    Passenger* Booking; //contains detail of passenger and thier seat No
    string FlightNo;
    Schedule S; // Contains Flight Take Off Times
    int Expense;
public:
    Airplane(string FlightN, Schedule Sec,int Exp) {
        Seating = 60;
        FlightNo = FlightN;
        S = Sec;
        AllocateMem();
        Expense = Exp;
    }
    Airplane() {
        Seating = 60;
        FlightNo = "N/A";
        Schedule A;
        S = A;
        AllocateMem();
        Expense = 0;
    }
    void ShowBookings();
    Airplane(const Airplane& A);
    void Change_Status(string s) 
    {
        S.setStatus(s);
    }
    void Change_Timing(string dt, string at)
    {
        try
        {
            if (at.size() != 5 || at[2] != ':')
            {
                throw string("Invalid Arrival Time Format Used");
            }
            if (dt.size() != 5 || dt[2] != ':')
            {
                throw string("Invalid Departure Time Format Used");
            }
            S.setDepartureTime(dt);
            S.setArrival(at);
        }
        catch (string s)
        {
            cout << s << endl;
        }
        
    }
    string getDeparture() 
    {
        return S.getOrigin();
    }
    string getDestination()
    {
        return S.getDestination();
    }
    void BookSeat(Passenger P, int Seat);  
    void Cancel_Bookings();
    void UnBookSeat(int Seat);
    void ChangeSchedule(Schedule Sa)
    {
    
        try 
        {
            if (Sa.getArrival().size() != 5 || Sa.getArrival()[2]!=':')
            {
                throw string("Invalid Arrival Time Format Used");
            }
            if (Sa.getDepartureTime().size() != 5 || Sa.getDepartureTime()[2] != ':')
            {
                throw string("Invalid Departure Time Format Used");
            }
            S = Sa;
        }
        catch(string s)
        {
            cout << s << endl;
        }
       
    }
    void Change_Path(string d, string a)
    {
        S.setOrigin(d);
        S.setDestination(a);
    }
    string getFlightno() 
    {
        return FlightNo;
    }
    void Change_Seating(int S)
    {
        if (S > 0 && S < 60)
        {
            Seating = S;
        }
        else
        {
            cout << "Either you Entered A Negative VAlue Or The Number exceeds Flight Max Population" << endl;
        }
    }
    ostream& Display(ostream& out)
    {
        out << "FlightNo\tSeating" << endl;
        out << FlightNo << "\t\t" << Seating << endl;
        out << S << endl;
        out <<"Expenses Rs. " << Expense;
        return out;
    }
    friend ostream& operator<<(ostream& out, Airplane S)
    {
        return S.Display(out);
    }
    void AllocateMem();
};
class Airport {
private:
    Airplane* Planes;
    string Name;
    int Capacity;// contain max planes standing
    bool Airport_Loc; // it will be 1 for North And 0 For South
    int capcount; // contain current planes standing
public:
    Airport(string n, bool Airport_L, Airplane* A, int numofplane)
    {
        Name = n;
        Airport_Loc = Airport_L;
        capcount = numofplane;
        Capacity = 5;
        Planes = new Airplane[Capacity];
        Planes = A;
        
    }
    Airport() {
        Name = "N/A";
        Airport_Loc = false;
        Capacity = 5;
        Planes = new Airplane[Capacity];
        for (int i = 0; i < Capacity; i++) {
            Planes[i] = Airplane();
        }
        capcount = 0;
    }
    Airport(Airport& A) {
        Planes = new Airplane[A.capcount];
        Name = A.Name;
        Airport_Loc = A.Airport_Loc;
        Capacity = A.Capacity;
        Planes = new Airplane[Capacity];
        for (int i = 0; i < Capacity; i++) {
            Planes[i] = A.Planes[i];
        }
        capcount = A.capcount;
    }
    string getname() 
    {
        return Name;
    }
    Airplane* getAirplane() 
    {
                return Planes;    
        
    }
    friend ostream& operator<<(ostream& out, Airport& A)
    {
        out << "Name\t\tAvailableFlights\tAirport_Location" << endl;
        out << A.Name << "\t" << A.capcount << "\t\t\t";
        if (A.Airport_Loc == 0)
        {
            out << "South" << endl;
        }
        else
        {
            out << "North" << endl;
        }
        out << "------------------------------------------" << endl;
        for (int i = 0; i < A.capcount; i++)
        {
            out << "***************************" << endl;
            out << A.Planes[i];
        }
        return out;

    }
    int getcap()
    {
        return capcount;
    }
};
class Person {
protected:
    string Name;
    string Phone_No;
    string Username;
    string Password;
public:
    Person() {
        Name = "N/A";
        Phone_No = "N/A";
        Username = "N/A";
        Password = "N/A";
    }
    Person(string n, string p, string us, string pa) {
        Name = n;
        Phone_No = p;
        Username = us;
        Password = pa;

    }
};
class Payment_Account {
private:
    string Acc_num;
    string CVV;
    string Expire_date;
public:
    Payment_Account() {
        Acc_num = "N/A";
        CVV = "N/A";
        Expire_date = "N/A";
    }
    Payment_Account(string an, string cvv, string expire_date) {
        Acc_num = an;
        CVV = cvv;
        Expire_date = expire_date;
    }
    Payment_Account(Payment_Account& P)
    {
        Acc_num = P.Acc_num;
        CVV = P.CVV;
        Expire_date = P.Expire_date;
    }
    string  getexp() 
    {
        return Expire_date;
    }
    string  getacc()
    {
        return Acc_num;
    }
    string  getcvv()
    {
        return CVV;
    }
};
class Passenger : Person
{
private:
    friend class Passeger_Panel;
    bool VISA; // 0 for rejected 1 for Approved
    string CNIC;
    int Age;
    int seat_No;
    Payment_Account Acc;
public:
    Passenger(string n, string p, string us, string pa, bool V, string c, int a, Payment_Account Payment_Acc, int seat) :Person(n, p, us, pa)
    {
        VISA = V;
        CNIC = c;
        Age = a;
        Acc = Payment_Acc;
        seat_No = seat;
    }
    int getseat()
    {
        return seat_No;
    }
    Passenger() :Person()
    {
        VISA = "N/A";
        CNIC = "N/A";
        Age = 0;
        Payment_Account P;
        Acc = P;
        seat_No = 0;
    }
    ostream& Display(ostream& out)
    {
        out << "PassengerName\tVISA\tAge\tCNIC" << endl;
        out << Name << "\t\t";
        if (VISA == 1)
        {
            out << "VALID" << "\t";
        }
        else
        {
            out << "INVALID" << "\t";
        }
        out << Age << "\t" << CNIC << endl;
        return out;
    }
    friend ostream& operator <<(ostream& out, Passenger P)
    {
        P.Display(out);
        return out;
    }
    string getname() 
    {
        return Name;
    }
};
class NAFS_Staff : Person
{
private:
    string Unique_Id; //every Staff member has a unique Id which gives them Privilges of Admin PAnel (Note it is 4 digits); 
public:
    NAFS_Staff(string n, string p, string us, string pa, string ui) :Person(n, p, us, pa)
    {
        Unique_Id = ui;
    }
    NAFS_Staff() :Person()
    {
        Unique_Id = "N/A";
    }
    string Getid()
    {
        return Unique_Id;
    }
    string getus()
    {
        return Username;
    }
    string getpass() 
    {
        return Password;
    }
};
class Admin_Panel
{
private:
    Airport* Airports; //contains all airport details to be accessed by Admins
    int numofAirport;
    NAFS_Staff* Active_Staff; // it contains The Staff that are registered in NAFS system
    int numofStaff;
public:
    Admin_Panel()
    {
        Active_Staff = new NAFS_Staff[0];
        numofStaff = 0;
        numofAirport = 0;
        Airports = new Airport[0];
    }
    Admin_Panel(NAFS_Staff* A, int size,Airport* Air, int NA)
    {
        Active_Staff = new NAFS_Staff[size];
        numofStaff = size;
        for (int i = 0; i < size; i++)
        {
            Active_Staff[i] = A[i];
        }
        numofAirport = NA;
        Airports = Air;
    }
    void RestrictAirplane(string name,int fno,int size) 
    {
        for (int i = 0; i < numofAirport; i++)
        {
            if (Airports[i].getname() == name) 
            {
                Airports[i].getAirplane()[fno].Change_Seating(size);
            }
        }
    }
    void Cancel_Flight(string name,int j) 
    {
        for (int i = 0; i < numofAirport; i++)
        {
            if (Airports[i].getname() == name)
            {
                Airports[i].getAirplane()[j].Change_Status("Cancelled");
                Airports[i].getAirplane()[j].Cancel_Bookings();
                Airports[i].getAirplane()[j].Change_Timing("--:--", "--:--");
                Airports[i].getAirplane()[j].Change_Path("--:--", "--:--");
            }
        }
    } //Cancel flight cancels the flight and Delete all bookings of it whereas halt just delays that flight ratther than deleting it
    void Halt_Flight(string name, int j)
    {
        for (int i = 0; i < numofAirport; i++)
        {
            if (Airports[i].getname() == name)
            {
                Airports[i].getAirplane()[j].Change_Status("Halted");
            }
        }
    }
    bool checkMember(string us,string pas)
    {
        for (int i = 0; i < numofStaff; i++)
        {
            if (Active_Staff[i].getus() == us && Active_Staff[i].getpass() == pas)
            {
                return true;
            }
        }
        return false;
    }
    void Change_Schedule(string name,int fno, string departtime, string arrivetime){
        for (int i = 0; i < numofAirport; i++)
        {
            if (Airports[i].getname() == name) {
                Airports[i].getAirplane()[fno].Change_Timing(departtime, arrivetime);
            
            }
        }
    
    }
    void Change_Path(string name,int fno, string Origin, string Destiny)
    {
        for (int i = 0; i < numofAirport; i++)
        {
            if (Airports[i].getname() == name) {
               
                Airports[i].getAirplane()[fno].Change_Path(Origin,Destiny);
            }
        }
    }
    void DisplayFlights() 
    {
        for (int i = 0; i < numofAirport; i++) 
        {
            cout << Airports[i];
        }
    }
};
class Passeger_Panel
{
private:
    Passenger* PassengerList; //contains registered Users;
    int No_of_Passenger;
    Airport* Airports; // to let Passengers Book FLights
    int numofairports;
public:
    Passeger_Panel()
    {
        PassengerList = new Passenger[0];
        No_of_Passenger = 0;
        Airports = NULL;
        numofairports = 0;
    }
    Passeger_Panel(Passenger* P, int si,Airport* A,int NA)
    {
        PassengerList = new Passenger[si];
        PassengerList = P;
        No_of_Passenger = si;
        Airports = A;
        numofairports=NA;
    }

    bool Check_Passenger(string username, string pass)
    {
        for (int i = 0; i < No_of_Passenger; i++)
        {
            if (username == PassengerList[i].Username && pass == PassengerList[i].Password)
            {
                return 1;
            }
        }
        return 0;
    }
    Passenger SearchPassenger(string us,string pass) 
    {
        for (int i = 0; i < No_of_Passenger; i++) 
        {
            if (PassengerList[i].Username == us && PassengerList[i].Password == pass) 
            {
                return PassengerList[i];
            }
        }
        Passenger P;
        return P;
    }
    bool BookSeat(string depart, string arrival,int no,Passenger P) 
    {
        
            for (int i = 0; i < numofairports; i++) 
            {
             
                for (int j = 0; j < 5; j++) 
                {
                    if (Airports[i].getAirplane()[j].getDeparture() == depart && Airports[i].getAirplane()[j].getDestination() == arrival)
                    {
                        Airports[i].getAirplane()[j].BookSeat(P, no);
                        return 1;
                    }
                }
            }
            return 0;
    }
    bool UpdateUsername(string username,string  pass,string newusername) 
    {
        for (int i = 0; i < No_of_Passenger; i++)
        {
            if (PassengerList[i].Username == username && PassengerList[i].Password == pass)
            {
                PassengerList[i].Username=newusername;
                return 1;
            }
        }
        return 0;
    }
    bool UpdatePass(string username, string  pass, string newpass)
    {
        for (int i = 0; i < No_of_Passenger; i++)
        {
            if (PassengerList[i].Username == username && PassengerList[i].Password == pass)
            {
                PassengerList[i].Password = newpass;
                return 1;
            }
        }
        return 0;
    }
    bool UnBookSeat(string depart, string arrival, int no)
    {

        for (int i = 0; i < numofairports; i++)
        {

            for (int j = 0; j < 5; j++)
            {
                if (Airports[i].getAirplane()[j].getDeparture() == depart && Airports[i].getAirplane()[j].getDestination() == arrival)
                {
                    Airports[i].getAirplane()[j].UnBookSeat(no);
                    return 1;
                }
            }
        }
        return 0;
    }
    void Register_Passenger()
    {
        bool num = 0, uc = 0, lc = 0, sc = 0;
        string acc, cvv, exp;
        string usern, password, phno, Name, CNIC,pass;
        int Age;
        char ch;
    Begining:
        try
        {

            cout << "Enter Your Name" << endl;
            getline(cin, Name);
            getline(cin, Name);
            if (Name == "")
            {
                throw string("Name Cannot Be Empty");
            }
            cout << "Enter Your Username" << endl;
            getline(cin, usern);
            if (usern == "")
            {
                throw string("UserName Cannot Be Empty");
            }
            cout << "Enter Your Password" << endl;
            ch = _getch();
            while (1) 
            {
                if (ch == 13) 
                {
                    break;
                }
                password.push_back(ch);
                cout << "*";
                ch = _getch();
            }
            cout << endl;
            cout << "Re-Enter Your Password" << endl;
            ch = _getch();
            while (1)
            {
                if (ch == 13)
                {
                    break;
                }
                pass.push_back(ch);
                cout << "*";
                ch = _getch();
            }
            cout << endl;
            if (password != pass) 
            {
                throw string("Your Password Does Not Match The one you entered");
            }
            if (password == "" || password.length() < 8 || password == "")
            {
                throw string("Password Must be atleast 8 characters");
            }
            for (int i = 0; i < password.length(); i++)
            {
                if (isupper(password[i]) == true)
                {
                    uc = true;
                }
                if (islower(password[i]) == true)
                {
                    lc = true;
                }
                if ((password[i] >= 32 && password[i] <= 47) || (password[i] >= 58 && password[i] <= 64) || (password[i] >= 91 && password[i] <= 96) || (password[i] >= 123 && password[i] <= 126))
                {
                    //these are ascii ranges in which all special characters lie
                    sc = true;
                }
                if (password[i] >= 47 && password[i] <= 59)
                {
                    num = true;
                }
            }
            if (sc = false)
            {
                throw string("Password Must be atleast 1 special character");
            }
            if (lc = false)
            {
                throw string("Password Must be atleast 1 lowercase");
            }
            if (uc = false)
            {
                throw string("Password Must be atleast 1 Upper Case");
            }
            if (num = false)
            {
                throw string("Password Must be atleast 1 Number");
            }
            cout << "Enter Your CNIC" << endl;
            cin >> CNIC;
            if (CNIC.length() != 13)
            {
                throw string("Invalid CNIC");
            }
            for (int i = 0; i < No_of_Passenger; i++) 
            {
                if (PassengerList[i].CNIC == CNIC) 
                {
                    throw string("It seems like your Cnic is repeating with a preregitered passenger please make sure you enter correct cnic");
                }
            }
            cout << "Enter Your phoneNo" << endl;
            cin >> phno;
            if (phno == "" || phno.length() != 11)
            {
                throw string("Phone Number Must have 11 Digits");
            }
            cout << "Enter Your Age" << endl;
            cin >> Age;
            if (Age <= 0)
            {
                throw string("Not a Valid Age");
            }
            cout << "-----------------PAYMENT INFO----------------" << endl;
            cout << "Enter Account Number" << endl;
            cin >> acc;
            if (acc.length() != 14)
            {
                throw string("Account Number is Not Valid");
            }
            cout << "Enter CVV" << endl;
            cin >> cvv;
            if (cvv.length() != 3)
            {
                throw string("CVV is Incorrect");
            }
            cout << "Enter Expiry Date (Format: MMYY )" << endl;
            cin >> exp;
            if (exp.length() != 4)
            {
                throw string("Please Use Correct format for expiry date and make sure to enter positive date");
            }
        }
        catch (string s)
        {
            cout << s << endl;
            cout << "You are Being redirected to Start" << endl;
            goto Begining;
        }
        Payment_Account P(acc, cvv, exp);
        Passenger NEw(Name, phno, usern, password, 1, CNIC, Age, P, 0); // 0 mean not assigned
        Passenger* newList = new Passenger[No_of_Passenger + 1];
        for (int i = 0; i < No_of_Passenger; i++)
        {
            newList[i] = PassengerList[i];
        }
        newList[No_of_Passenger] = NEw;
        PassengerList = newList;
        No_of_Passenger++;
    } //contains all the validation and constraint for the registration of user
    ostream& Display(ostream& out)
    {
        for (int i = 0; i < No_of_Passenger; i++)
        {
            out << PassengerList[i];
        }
        return out;
    }
    friend ostream& operator<<(ostream& out, Passeger_Panel& P)
    {
        return P.Display(out);
    }
};
void Airplane::AllocateMem()
{
    Booking = new Passenger[60];
}
void Airplane::ShowBookings()
{
    for (int i = 0; i < Seating; i++)
    {
        cout << Booking[i];
    }
}
void Airplane::BookSeat(Passenger P, int Seat)
{
    try
    {
        if ( Seat < 0 || Seat > 60)
        {
            throw string("Seat No is Invalid");
        }
        if (Booking[Seat].getname() != "N/A") 
        {
            throw string("Seat Is Booked");
        }
        Booking[Seat] = P;
    }
    catch (string s)
    {
        cout << s << endl;
    }
    Seating--;
}
bool Finaincial_Verification(Payment_Account P) 
{
    if (P.getacc().length() != 14) 
    {
        return false;
    }
    if (P.getcvv().length()>3)
    {
        return false;
    }
    if (P.getexp()[0]<51)
    {
        return false;
    }
    return true;
}
void Airplane::Cancel_Bookings()
{
    Passenger* P = new Passenger[60];
    Booking = P;
}
void Airplane::UnBookSeat(int Seat)
{
    try
    {
        if (Seat < 0 || Seat > 60)
        {
            throw string("Seat is Booked");
        }
        Passenger P;
        Booking[Seat] = P;
        cout << "Your Refund Is  "<<Expense*0.25 << endl;
    }
    catch (string s)
    {
        cout << s << endl;
    }
    Seating++;
}
Airplane::Airplane(const Airplane& A) {
    Booking = new Passenger[A.Seating];
    Seating = A.Seating;
    FlightNo = A.FlightNo;
    S = A.S;
    Booking = A.Booking;
    Expense = A.Expense;
}
int main() // main is working like a menu rather than making a menu class or function
{
    NAFS_Staff Joe("Joe","0301650032","Joe@321","12@321Dock","4584");
    NAFS_Staff Mike("Mike", "0305331223", "Mike@112", "12@321Mark", "4582");
    NAFS_Staff Harry("Harry", "0301650034", "Harry@212", "12@321Spade", "4581");
    NAFS_Staff STAFF[] = {Joe,Mike,Harry};
    Payment_Account CastroAcc("1832102392112", "312", "0127");
    Passenger Castro("Castro","0301560032","Capti","12E2d786@",1,"3320271705219",25,CastroAcc,0);
    Payment_Account JamesAcc("1832101232319", "422", "1229");
    Passenger James("James", "0301560032", "Sparrow", "12E1786@", 1, "3320213205219", 37, JamesAcc, 0);
    Payment_Account WillsAcc("1832102392139", "312", "1233");
    Passenger Will("Will", "0301560032", "WillwasJAck", "Encrypt@d", 1, "3320234215219", 23, WillsAcc, 0);
    Passenger Pass[] = {Castro,James,Will};
    // Schedule objects
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
    // Airplane objects
    Airplane a1("SUA1234", s1,54000);
    Airplane a2("SAA2345", s2, 12000);
    Airplane a3("SDL3456", s3, 32040);
    Airplane a4("SWN4567", s4, 12420);
    Airplane a5("SB65678", s5, 12200);
    Airplane a6("NUA1234", s6, 23000);
    Airplane a7("NAA2345", s7, 120000);
    Airplane a8("NDL3456", s8, 32040);
    Airplane a9("NWN4567", s9, 12420);
    Airplane a10("NB65678", s10, 12200);
    // Airport objects
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
    Airport Airs[] = {airport1,airport2,airport3,airport4,airport5,airport6,airport7,airport8,airport9,airport10};
    Admin_Panel ADMINS(STAFF, 3,Airs,10);  // created a panel with 3 members of NAFS STaff to handle operations of Admin_PAnel
    Passeger_Panel PASSENERS(Pass, 3,Airs,10); // Creates 3 Passenger that are preregistered
    string username, pass, name;
    string depart, arrival, departtime, arrivaltime;
    string newusername, newpass,newpass1;
    bool uc, lc, num, sc;
    Passenger tempP;
    char ch=' ';
    int res;
    int fno;
    cout << "----------------------NUCES AIRLINE---------------------------" << endl;
START:
    pass = "";
    newpass = "";
    cout << "Please Select Your Correct Designation For Best Experience" << endl;
    cout << "1. Admin Member" << endl;
    cout << "2. Passenger" << endl;
    cout << "3. New To NAFS Register Today" << endl;
    cout << "4. See Ongoing Flights" << endl;
    cout << "5. More About Us" << endl;
    cout << "6. Exit" << endl;
    int n;
    cin >> n;
    switch (n) 
    {
    case 1:
        cout << "Enter Your Username" << endl;
        getline(cin, username);//due to some bugs in terminal enter was automatically getting pressed in option selection so i entered getline twice
        getline(cin, username);
        cout << "Enter Your Password" << endl;
        ch = _getch();
        while (1)
        {
            if (ch == 13)
            {
                break;
            }
            pass.push_back(ch);
            cout << "*";
            ch = _getch();
        }
        cout << endl;
        if (ADMINS.checkMember(username, pass) == 1) 
        {
        ADMINMENU:
            pass = "";
            newpass = "";
            cout << "-------------------WELCOME-------------------" << endl;
            cout << "1. Restrict Passengers" << endl;
            cout << "2. Change Schedule " << endl;
            cout << "3. Change Path/Routes Of Flight" << endl;
            cout << "4. Update Inquiry" << endl;
            cout << "5. Display Airlines" << endl;
            cout << "6. Halt Flight" << endl;
            cout << "7. Cancel Flight" << endl;
            cout << "8. Return" << endl;
            cout << "9. exit" << endl;
            cin >> n;
            switch(n) 
            {
            case 1:
                try {
                    cout << "Enter The Airport Name " << endl;
                    cin >> name;
                    if (name != "Islamabad" && name != "Lahore" && name != "Peshawar" && name != "Quetta" && name != "Karachi")
                    {
                        cout << "Non-Existing Airport" << endl;
                        goto ADMINMENU;
                    }
                    cout << "Enter The Flight No of Plane You Wish To Restrict" << endl;
                    cin >> fno;
                    fno--;
                    if (fno > 5) 
                    {
                        cout << "Non-Existant Flight" << endl;
                        goto ADMINMENU;
                    }
                   cout << "Enter the restricted seats" << endl;
                   cin >> res;
                   ADMINS.RestrictAirplane(name, fno,res);
                }
                catch (string s)
                {
                    cout << s << endl;
                    goto ADMINMENU;
                }
                goto ADMINMENU;
                break;
            case 2:
                    cout << "Enter The Airport Name " << endl;
                    cin >> name;
                    if (name != "Islamabad" && name != "Lahore" && name != "Peshawar" && name != "Quetta" && name != "Karachi")
                    {
                        cout << "Non-Existing Airport" << endl;
                        goto ADMINMENU;
                    }
                    cout << "Enter The Flight No of Plane You Wish To Restrict" << endl;
                    cin >> fno;
                    fno--;
                    if (fno > 5)
                    {
                        cout << "Non-Existant Flight" << endl;
                        goto ADMINMENU;
                    }
                    cout << "Enter the The New Schedule Departure Time" << endl;
                    cin >> departtime;
                    cout << "Enter the The New Schedule Arrival Time" << endl;
                    cin >> arrivaltime;
                    ADMINS.Change_Schedule(name, fno, departtime, arrivaltime);
                goto ADMINMENU;
                break;
            case 3:
                cout << "Enter The Airport Name " << endl;
                cin >> name;
                if (name != "Islamabad" && name != "Lahore" && name != "Peshawar" && name != "Quetta" && name != "Karachi")
                {
                    cout << "Non-Existing Airport" << endl;
                    goto ADMINMENU;
                }
                cout << "Enter The Flight No of Plane You Wish To Restrict" << endl;
                cin >> fno;
                fno--;
                if (fno > 5)
                {
                    cout << "Non-Existant Flight" << endl;
                    goto ADMINMENU;
                }
                cout << "Enter the The New Schedule Departure Place" << endl;
                cin >> depart;
                cout << "Enter the The New Schedule Destination" << endl;
                cin >> arrival;
                ADMINS.Change_Path(name, fno, depart, arrival);
                goto ADMINMENU;
                break;
            case 4:
                cout << "Enter The Airport Name " << endl;
                cin >> name;
                if (name != "Islamabad" && name != "Lahore" && name != "Peshawar" && name != "Quetta" && name != "Karachi")
                {
                    cout << "Non-Existing Airport" << endl;
                    goto ADMINMENU;
                }
                cout << "Enter The Flight No of Plane You Wish To Restrict" << endl;
                cin >> fno;
                fno--;
                if (fno > 5)
                {
                    cout << "Non-Existant Flight" << endl;
                    goto ADMINMENU;
                }
                cout << "Enter the The New Schedule Departure Time" << endl;
                cin >> departtime;
                cout << "Enter the The New Schedule Arrival Time" << endl;
                cin >> arrivaltime;
                cout << "Enter the The New Schedule Departure Place" << endl;
                cin >> depart;
                cout << "Enter the The New Schedule Destination" << endl;
                cin >> arrival;
                ADMINS.Change_Path(name, fno, depart, arrival);
                ADMINS.Change_Schedule(name, fno, departtime, arrivaltime);
                goto ADMINMENU;
                break;
            case 5:
                ADMINS.DisplayFlights();
                goto ADMINMENU;
                break;
            case 6:
                cout << "Enter The Airport Name " << endl;
                cin >> name;
                if (name != "Islamabad" && name != "Lahore" && name != "Peshawar" && name != "Quetta" && name != "Karachi")
                {
                    cout << "Non-Existing Airport" << endl;
                    goto ADMINMENU;
                }
                cout << "Enter The Flight No of Plane You Wish To Restrict" << endl;
                cin >> fno;
                fno--;
                if (fno > 5)
                {
                    cout << "Non-Existant Flight" << endl;
                    goto ADMINMENU;
                }
                ADMINS.Halt_Flight(name, fno);
                goto ADMINMENU;
                break;
            case 7:
                cout << "Enter The Airport Name " << endl;
                cin >> name;
                if (name != "Islamabad" && name != "Lahore" && name != "Peshawar" && name != "Quetta" && name != "Karachi")
                {
                    cout << "Non-Existing Airport" << endl;
                    goto ADMINMENU;
                }
                cout << "Enter The Flight No of Plane You Wish To Restrict" << endl;
                cin >> fno;
                fno--;
                if (fno > 5)
                {
                    cout << "Non-Existant Flight" << endl;
                    goto ADMINMENU;
                }
                ADMINS.Cancel_Flight(name, fno);
                goto ADMINMENU;
                break;
                
            case 8:
                goto START;
                break;
            case 9:
                exit(0);
                goto ADMINMENU;
                break;
            default:
                cout << "INVALID SELECTION" << endl;
                goto ADMINMENU;
                break;
            }

        }
        else 
        {
            cout << "You are Not a Registered Member Please Proceed Back" << endl;
        }
        goto START;
        break;
    case 2:
        cout << "Enter Your Username" << endl;
        getline(cin, username);//due to some bugs in terminal enter was automatically getting pressed in option selection so i entered getline twice
        getline(cin, username);
        cout << "Enter Your Password" << endl;
        ch = _getch();
        while (1)
        {
            if (ch == 13)
            {
                break;
            }
            pass.push_back(ch);
            cout << "*";
            ch = _getch();
        }
        if (PASSENERS.Check_Passenger(username,pass)==1)
        {
        USERPANEL:
            cout << endl;
            cout << "1. Book Flight" << endl;
            cout << "2. View Flight Details" << endl;
            cout << "3. Cancel Flight" << endl;
            cout << "4. Reset Username" << endl;
            cout << "5. Reset Password" << endl;
            cout << "6. Return" << endl;
            cout << "7. Exit" << endl;
            cin >> n;
            switch (n) 
            {
            case 1:
                cout << "Enter Your Origin" << endl;
                getline(cin, depart);
                getline(cin, depart);
                cout << "Enter Your Destination" << endl;
                getline(cin, arrival);
                cout << "Enter Seat No You Wish To Book" << endl;
                cin >> fno;
                if (fno > 60 || fno < 0) 
                {
                    cout << "Invalid Seat Selected" << endl;
                }
              tempP=  PASSENERS.SearchPassenger(username, pass);
              if (PASSENERS.BookSeat(depart, arrival, fno, tempP)==1) 
              {
                  cout << "Booking Successful" << endl;
              }
              else 
              {
                  cout << "Booking Failed" << endl;
              }
              goto START;
                break;
            case 2:
                ADMINS.DisplayFlights();
                goto USERPANEL;
                break;
            case 3:
                cout << "Please Enter Some Details for unbooking firstly tell your Origin of Flight" << endl;
                getline(cin, depart);
                getline(cin, depart);
                cout << "Enter Your Destination" << endl;
                getline(cin, arrival);
                cout << "Enter Seat No You Wish To UnBook" << endl;
                cin >> fno;
                if (fno > 60 || fno < 0)
                {
                    cout << "Invalid Seat Selected" << endl;
                }
                tempP = PASSENERS.SearchPassenger(username, pass);
                if (PASSENERS.UnBookSeat(depart, arrival, fno) == 1)
                {
                    cout << "UnBooking Successful" << endl;
                }
                else
                {
                    cout << "UnBooking Failed" << endl;
                }
                goto START;
                break;
            case 4:
                cout << "Enter Your new Username" << endl;
                getline(cin,newusername);
                getline(cin, newusername);
                if (PASSENERS.UpdateUsername(username, pass, newusername) == 1) 
                {
                    cout << "Updated Successfully" << endl;
                }
                else 
                {
                    cout << "Updation Unsuccessful" << endl;
                }
                goto USERPANEL;
                break;
            case 5:
                cout << "Enter Your new Password" << endl;
                try 
                {
                    ch = _getch();
                    while (1)
                    {
                        if (ch == 13)
                        {
                            break;
                        }
                        newpass.push_back(ch);
                        cout << "*";
                        ch = _getch();
                    }
                    cout << endl;
                    cout << "Re-Enter Your Password" << endl;
                    ch = _getch();
                    while (1)
                    {
                        if (ch == 13)
                        {
                            break;
                        }
                        newpass1.push_back(ch);
                        cout << "*";
                        ch = _getch();
                    }
                    cout << endl;
                    if (newpass != newpass1)
                    {
                        throw string("Your Password Does Not Match The one you entered");
                    }
                    if (newpass == "" || newpass.length() < 8 || newpass == "")
                    {
                        throw string("Password Must be atleast 8 characters");
                    }
                    for (int i = 0; i < newpass.length(); i++)
                    {
                        if (isupper(newpass[i]) == true)
                        {
                            uc = true;
                        }
                        if (islower(newpass[i]) == true)
                        {
                            lc = true;
                        }
                        if ((newpass[i] >= 32 && newpass[i] <= 47) || (newpass[i] >= 58 && newpass[i] <= 64) || (newpass[i] >= 91 && newpass[i] <= 96) || (newpass[i] >= 123 && newpass[i] <= 126))
                        {
                            //these are ascii ranges in which all special characters lie
                            sc = true;
                        }
                        if (newpass[i] >= 47 && newpass[i] <= 59)
                        {
                            num = true;
                        }
                    }
                    if (sc = false)
                    {
                        throw string("Password Must be atleast 1 special character");
                    }
                    if (lc = false)
                    {
                        throw string("Password Must be atleast 1 lowercase");
                    }
                    if (uc = false)
                    {
                        throw string("Password Must be atleast 1 Upper Case");
                    }
                    if (num = false)
                    {
                        throw string("Password Must be atleast 1 Number");
                    }
                }
                catch (string s) 
                {
                    cout << s << endl;
                }
                if (PASSENERS.UpdatePass(username, pass, newpass) == 1)
                {
                    cout << "Updated Successfully" << endl;
                }
                else
                {
                    cout << "Updation Unsuccessful" << endl;
                }
                goto USERPANEL;
                break;
            case 6:
                goto START;
                break;
            default :
                cout << "Invalid Selection Please Select According to Number" << endl;
                goto USERPANEL;
                    break;
            }

        }
        else
        {
            cout << "You are Not a Registered Passenger But You can Always Register :)" << endl;
        }
        goto START;
        break;
    case 3:
        PASSENERS.Register_Passenger();
        goto START;
        break;
    case 4:
        ADMINS.DisplayFlights();
        goto START;
        break;
    case 5:
        cout << "NUCES Airline System is a newly made Airline Management System created by our finest Staff and Developers to Provide Ease of Access to our Dear Passengers. We prefer Quality over Quantity Hence we have limited Airlines But Top Notch. Moreever we provide services over 32 countries and 5 cities of Pakistan That are\n Lahore\nIslamabad\nQuetta\nPeshawar\nKarachi" << endl;
        goto START;
        break;
    case 6:
        exit(0);
        break;
    default:
        cout << "Invalid Selection please Try Again" << endl;
        goto START;
        break;
    }
    return 0;
}
