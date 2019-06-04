cmake_minimum_required(VERSION 3.10)
project(arvore-b-disco)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(arvore-b-disco
        arvore_b.c
        arvore_b.h
        cliente.c
        cliente.h
        lista_clientes.c
        lista_clientes.h
        lista_nos.c
        lista_nos.h
        Makefile
        metadados.c
        metadados.h
        no.c
        no.h
        test_arvore_b.c
        ufftest.h)
