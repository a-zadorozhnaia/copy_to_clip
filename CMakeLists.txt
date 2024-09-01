cmake_minimum_required(VERSION 3.0.0)
project(copy_to_clip VERSION 0.1.0 LANGUAGES C CXX)

add_executable(copy_to_clip
    main.cpp
    path_checker.hpp
    path_checker.cpp
    test.hpp
    test.cpp
    clip.hpp
    clip.cpp)
