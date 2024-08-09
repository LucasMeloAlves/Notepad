cmake_minimum_required(VERSION 3.27)
project(Notepad)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/home/lucas/Qt/6.6.2/gcc_64/lib/cmake")

set(QT_VERSION 6)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt6::Core Qt6::Gui Qt6::Widgets)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Notepad main.cpp
        Note.h
        Collection.h
        Observer.h
        Subject.h
        CollectionCount.h)
target_link_libraries(Notepad
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

