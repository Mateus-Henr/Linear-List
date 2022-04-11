cmake_minimum_required(VERSION 3.21)
project(TP1 C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(TP1 src/main.c src/arquivo.c src/lista.c src/processo.c)
