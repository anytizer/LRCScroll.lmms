cmake_minimum_required(VERSION 3.31)

project(LRCScroll VERSION 1.0 LANGUAGES CXX)

# 1. Automate Qt's Meta-Object Compiler and UI tools
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 2. Locate the Qt components (Widgets is the core for QPlainTextEdit)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# 3. Define the executable and its source files
add_executable(LRCScroll main.cpp ../plugin/TimestampEditor.cpp)

# 4. Link the Qt libraries to your executable
target_link_libraries(LRCScroll PRIVATE Qt6::Widgets)
