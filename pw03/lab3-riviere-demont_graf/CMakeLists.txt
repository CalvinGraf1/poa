cmake_minimum_required(VERSION 3.15)
project(river CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(river
        src/main.cpp
        src/people/Person.cpp
        src/people/Person.hpp
        src/people/noDrivers/NoDriver.cpp
        src/people/noDrivers/NoDriver.hpp
        src/people/noDrivers/childs/Son.cpp
        src/people/noDrivers/childs/Son.hpp
        src/people/noDrivers/childs/Daughter.cpp
        src/people/noDrivers/childs/Daughter.hpp
        src/people/drivers/Driver.cpp
        src/people/drivers/Driver.hpp
        src/people/noDrivers/Thief.cpp
        src/people/noDrivers/Thief.hpp
        src/people/drivers/Policeman.cpp
        src/people/drivers/Policeman.hpp
        src/Container/Container.cpp
        src/Container/Container.hpp
        src/Controller.cpp
        src/Controller.hpp
        src/Container/Boat.cpp
        src/Container/Boat.hpp
        src/Container/Bank.cpp
        src/Container/Bank.hpp
        src/people/noDrivers/childs/Child.cpp
        src/people/noDrivers/childs/Child.hpp
        src/people/drivers/Parent.hpp
        src/people/drivers/Parent.hpp
        src/people/drivers/Parent.cpp
        src/Validation.hpp
        src/Validation.cpp)
