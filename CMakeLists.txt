cmake_minimum_required(VERSION 3.21.1)
project(biblio C)

set(CMAKE_C_STANDARD 11)

add_executable(biblio main.c
        Function.h
        fileOps.c
        fileOps.h)
