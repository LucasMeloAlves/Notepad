cmake_minimum_required(VERSION 3.27)
project(Activities)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "/home/lucas/Qt/6.6.2/gcc_64/lib/cmake")


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Activities main.cpp)
target_link_libraries(Activities
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

