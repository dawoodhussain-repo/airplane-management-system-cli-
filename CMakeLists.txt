cmake_minimum_required(VERSION 3.10)
project(AirportManagementSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Source files
set(SOURCES
    src/Schedule.cpp
    src/Person.cpp
    src/Payment_Account.cpp
    src/Passenger.cpp
    src/NAFS_Staff.cpp
    src/Airplane.cpp
    src/Airport.cpp
    src/Admin_Panel.cpp
    src/Passenger_Panel.cpp
    src/Utilities.cpp
    main.cpp
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link libraries if needed
# target_link_libraries(${PROJECT_NAME} some_library)