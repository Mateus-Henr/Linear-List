cmake_minimum_required(VERSION 3.20)
project(Tp1 C)

set(CMAKE_C_STANDARD 99)

add_executable(Tp1 main.c "dados_processos.h" "celula.h" funcoes_teste.c "processo.h" "processo.c")
