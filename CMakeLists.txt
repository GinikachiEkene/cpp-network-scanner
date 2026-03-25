cmake_minimum_required(VERSION 3.10)
project(NetworkScanner)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(scanner
    src/main.cpp
    src/host_discovery.cpp
    src/port_scanner.cpp
)