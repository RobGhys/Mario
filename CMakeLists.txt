cmake_minimum_required(VERSION 3.25)
project(mario)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(mario main.cpp Utils.cpp Utils.h Mario.cpp Mario.h Box.h Box.cpp Direction.h GameObject.cpp GameObject.h Box.cpp)
target_link_libraries(mario
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

