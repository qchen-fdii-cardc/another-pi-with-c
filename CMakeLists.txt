cmake_minimum_required(VERSION 3.10)

project(pi_calculator VERSION 1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(pi_calculator src/main.c src/pi_spigot.c)

target_link_libraries(pi_calculator m)
