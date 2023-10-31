cmake_minimum_required(VERSION 3.24)
project(List)

set(CMAKE_CXX_STANDARD 17)

add_executable(List
        main.cpp
        AnimeList.h
        AnimeList.cpp
        inputs.h
        inputs.cpp
        completedAnime.h
        completedAnime.cpp
        notCompletedAnime.h
        notCompletedAnime.cpp)

add_executable(test
        testing.cpp
        AnimeList.h
        AnimeList.cpp
        inputs.h
        inputs.cpp
        completedAnime.h
        completedAnime.cpp
        notCompletedAnime.h
        notCompletedAnime.cpp)
