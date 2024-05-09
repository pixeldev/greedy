cmake_minimum_required(VERSION 3.28)
project(greedy C)

set(CMAKE_C_STANDARD 23)

add_executable(greedy main.c
        activities.c
        activities.h
        valued_activities.c
        valued_activities.h
        flip_coins.c
        flip_coins.h)
