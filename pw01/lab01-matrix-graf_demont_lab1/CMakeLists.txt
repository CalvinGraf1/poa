cmake_minimum_required(VERSION 3.10)
project(LabMatrix)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(matrix src/Matrix.cpp src/Matrix.hpp src/main.cpp
        src/MatrixOperations.hpp
        src/MatrixOperations.cpp
        src/Utils.hpp
        src/Utils.cpp)

if(MSVC)
    target_compile_options(matrix PRIVATE /W4 /WX)
else()
    target_compile_options(matrix PRIVATE -Wall -Wpedantic -Werror)
endif()
