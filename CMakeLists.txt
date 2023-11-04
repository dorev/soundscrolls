cmake_minimum_required(VERSION 3.10)

# Define project and language
project(SoundScrolls CXX)

# Add Qt path
set(QT6_PATH "C:/Qt/6.6.0/msvc2019_64")
set(CMAKE_PREFIX_PATH "${QT6_PATH}")

# Define the list of Qt modules
set(QT_MODULES Core WebSockets Network Sql Widgets)

# Find the required Qt packages
string(REPLACE " " ";" QT_MODULES_FIND "${QT_MODULES}")
find_package(Qt6 COMPONENTS ${QT_MODULES_FIND} REQUIRED)

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

# Link against the Qt modules
set(QT_MODULES_LINK "")
foreach(module ${QT_MODULES})
  list(APPEND QT_MODULES_LINK "Qt6::${module}")
endforeach()
target_link_libraries(${PROJECT_NAME} ${QT_MODULES_LINK})

# Deployment
if(WIN32)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${QT6_PATH}/bin/windeployqt $<TARGET_FILE:${PROJECT_NAME}>
    )
elseif(APPLE)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${QT6_PATH}/bin/macdeployqt $<TARGET_FILE_DIR:${PROJECT_NAME}>
    )
else()
    message(STATUS "Deployment on Linux is not supported through this CMake setup.")
endif()
