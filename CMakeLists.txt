cmake_minimum_required(VERSION 3.16)
project(Projekt_v2)

add_executable(Projekt_v2 main.cpp animation.cpp animation.h Player.cpp Player.h Collider.cpp Collider.h Platforms.cpp Platforms.h Enemy.cpp Enemy.h Menu.cpp Menu.h)
set(SFML_DIR "C:/SFML-2.5.1/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics audio system window REQUIRED)

target_link_libraries(Projekt_v2 sfml-graphics sfml-audio sfml-system sfml-window)