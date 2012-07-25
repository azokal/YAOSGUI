cmake_minimum_required(VERSION 2.6)
project(YAOSGUI)
set(CMAKE_CXX_FLAGS "-W -Wextra -Wall")
set(LIBRARY_OUTPUT_PATH lib)
include_directories(inc)
file(
        GLOB_RECURSE
        source_files
        src/*
        inc/*
)

add_library(
        YAOSGUI
        SHARED
        ${source_files}
)
