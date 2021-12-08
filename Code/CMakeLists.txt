cmake_minimum_required(VERSION 3.20)
project(Tp1 C)

set(CMAKE_C_STANDARD 99)

add_executable(Tp1 MAIN.c "DADOS PROCESSO.h" "PROCESSOS.h" FUNCOES_TESTE.c)
