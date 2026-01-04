cmake_minimum_required(VERSION 3.16)
project(CustomResizeProject)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets) # Or Qt5

add_executable(CustomResizeProject
    main.cpp
    CustomWindow.h
    CustomWindow.cpp
)

target_link_libraries(CustomResizeProject PRIVATE Qt6::Widgets)