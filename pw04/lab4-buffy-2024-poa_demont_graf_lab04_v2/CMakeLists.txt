cmake_minimum_required(VERSION 3.15)
project(buffy CXX)

set(CMAKE_CXX_STANDARD 23)

add_executable( buffy
        src/Action/Action.cpp
        src/Action/Action.hpp
        src/Action/Move.cpp
        src/Action/Move.hpp
        src/Action/Transform.cpp
        src/Action/Transform.hpp
        src/Action/Kill.cpp
        src/Action/Kill.hpp
        src/Person/Humanoid.cpp
        src/Person/Humanoid.hpp
        src/Person/Vampire.cpp
        src/Person/Vampire.hpp
        src/Person/Human.cpp
        src/Person/Human.hpp
        src/Person/Buffy.cpp
        src/Person/Buffy.hpp
        src/Field/Field.cpp
        src/Field/Field.hpp
        src/Utils/Position.cpp
        src/Utils/Position.hpp
        src/Displayer/Display.cpp
        src/Displayer/Display.hpp
        src/Controller/Controller.cpp
        src/Controller/Controller.hpp
        src/main.cpp src/Utils/Random.hpp src/Utils/Random.cpp src/Statistics/statisticsCalculator.cpp)
