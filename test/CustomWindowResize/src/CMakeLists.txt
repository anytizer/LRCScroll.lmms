cmake_minimum_required(VERSION 3.16)

project(resizer)

# Qt 6 requires at least C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets) # Or Qt5

add_executable(resizer
    main.cpp
    CustomWindow.h
    CustomWindow.cpp
)

target_link_libraries(resizer PRIVATE Qt6::Widgets)