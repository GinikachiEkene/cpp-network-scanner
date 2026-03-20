cmake_minimum_required(VERSION3.10)
project(cpp-network-scanner)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(scanner
    src/main.cpp
)