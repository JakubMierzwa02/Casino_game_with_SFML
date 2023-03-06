# Set a minimum CMake vversion
cmake_minimum_required(VERSION 3.8)

# Define our project name
project(Casino)

# Look for the SFML components we're interested in
find_package(SFML 2.4 COMPONENTS audio graphics window system REQUIRED)

add_executable(Casino
main.cpp
Casino.h
Casino.cpp
Phase.h
Phase.cpp
Poker.h
Poker.cpp
Card.h
Card.cpp
Hand.h
Hand.cpp
)

# Link our executable to SFML and its dependencies
target_link_libraries(Casino sfml-audio sfml-graphics sfml-window sfml-system)

# Set our source directory as the startup directory for debugging
set_target_properties(Casino PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})