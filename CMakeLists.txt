cmake_minimum_required(VERSION 3.10)

# Define project and language
project(SoundScrolls CXX)

# Find the Qt packages
find_package(Qt6 COMPONENTS Core WebSockets Network Sql REQUIRED)

# Specify C++ standard and compile flags
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# Glob source files
file(GLOB SRC
    "./src/*.cpp"
    "./src/*.h"
)

# Create executable and link libraries
add_executable(${PROJECT_NAME} ${SRC})
target_link_libraries(${PROJECT_NAME} Qt6::Core Qt6::WebSockets Qt6::Network Qt6::Sql)
