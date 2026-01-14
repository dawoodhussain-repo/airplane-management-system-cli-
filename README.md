# Airplane-Management-System-CLI

A comprehensive Airport Management System CLI application built in C++ that allows passengers to book flights, manage reservations, and provides administrative controls for airport staff.

## Features

### For Passengers:

- User registration with secure password validation
- Flight booking and cancellation
- View flight schedules and details
- Update username and password
- Secure payment account management

### For Administrators:

- Flight schedule management
- Route modifications
- Flight status control (halt/cancel)
- Passenger capacity restrictions
- Staff authentication

## Project Structure

```
Airport-Management-System-C--main/
├── CMakeLists.txt          # Build configuration
├── main.cpp               # Main application entry point
├── README.md              # Project documentation
├── include/               # Header files
│   ├── Schedule.h
│   ├── Person.h
│   ├── Payment_Account.h
│   ├── Passenger.h
│   ├── NAFS_Staff.h
│   ├── Airplane.h
│   ├── Airport.h
│   ├── Admin_Panel.h
│   ├── Passenger_Panel.h
│   └── Utilities.h
└── src/                   # Implementation files
    ├── Schedule.cpp
    ├── Person.cpp
    ├── Payment_Account.cpp
    ├── Passenger.cpp
    ├── NAFS_Staff.cpp
    ├── Airplane.cpp
    ├── Airport.cpp
    ├── Admin_Panel.cpp
    ├── Passenger_Panel.cpp
    └── Utilities.cpp
```

## Prerequisites

- C++17 compatible compiler (GCC, Clang, MSVC)
- CMake 3.10 or higher

## Building the Project

1. Clone or navigate to the project directory
2. Create a build directory:

   ```bash
   mkdir build
   cd build
   ```

3. Generate build files:

   ```bash
   cmake ..
   ```

4. Build the project:

   ```bash
   make
   ```

5. Run the application:
   ```bash
   ./AirportManagementSystem
   ```

## Usage

The application provides a menu-driven interface with the following options:

1. **Admin Member**: Login as airport staff
2. **Passenger**: Login as a registered passenger
3. **New Registration**: Register as a new passenger
4. **View Flights**: Display all available flights
5. **About Us**: Information about the airline system
6. **Exit**: Quit the application

## Key Classes

- **Schedule**: Manages flight timing and routing information
- **Passenger**: Represents airline passengers with booking capabilities
- **Airplane**: Handles flight operations and seat management
- **Airport**: Manages airport operations and airplane fleets
- **Admin_Panel**: Provides administrative controls
- **Passenger_Panel**: Manages passenger interactions

## Security Features

- Password validation with complexity requirements
- Secure input handling for sensitive information
- CNIC uniqueness validation
- Payment account verification

## Bug Fixes Applied

- Fixed memory management issues with dynamic arrays
- Corrected password validation logic (assignment vs comparison operators)
- Improved error handling with proper exceptions
- Fixed financial verification logic
- Enhanced input validation and bounds checking

## Contributing

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Test thoroughly
5. Submit a pull request

## License

This project is developed as part of a university assignment and is for educational purposes.
