cmake_minimum_required(VERSION 3.24)
project(SFML)

set(CMAKE_CXX_STANDARD 17)

set(SFML_DIR C:/Users/sdedf/.vcpkg-clion/vcpkg/scripts/buildsystems/vcpkg.cmake)
add_executable(SFML
        main5.cpp)
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
target_link_libraries(SFML sfml-graphics sfml-system sfml-window)