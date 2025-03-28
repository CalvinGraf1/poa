cmake_minimum_required(VERSION 3.10)
project(LabSquadron)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(main src/main.cpp
        src/ships/Ship.cpp
        src/ships/Ship.hpp
        src/ships/cargo/CargoShip.cpp
        src/ships/cargo/CargoShip.hpp
        src/ships/TIE.cpp
        src/ships/TIE.hpp
        src/ships/Interceptor.cpp
        src/ships/Interceptor.hpp
        src/ships/cargo/Shuttle.cpp
        src/ships/cargo/Shuttle.hpp
        src/ships/cargo/Destroyer.cpp
        src/ships/cargo/Destroyer.hpp
        src/Squadron.hpp
        src/Squadron.cpp
        src/Constants.hpp)

# Ajout de l'exécutable pour les tests
add_executable(tests
        src/tests/ShipTest.cpp
        src/ships/Ship.cpp
        src/ships/Ship.hpp
        src/ships/cargo/CargoShip.cpp
        src/ships/cargo/CargoShip.hpp
        src/ships/TIE.cpp
        src/ships/TIE.hpp
        src/ships/Interceptor.cpp
        src/ships/Interceptor.hpp
        src/ships/cargo/Shuttle.cpp
        src/ships/cargo/Shuttle.hpp
        src/ships/cargo/Destroyer.cpp
        src/ships/cargo/Destroyer.hpp
        src/Constants.hpp
)

# Ajout des dépendances pour les tests
target_link_libraries(tests gtest gtest_main)

# Ajout de la commande pour exécuter les tests
add_test(NAME ShipTest COMMAND tests)