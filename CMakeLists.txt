CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
PROJECT(boost)
LINK_DIRECTORIES("${boost_lib_dir}")
INCLUDE_DIRECTORIES("/home/pat/boost_1_69_0")
SET(boost_lib_dir "/home/pat/boost_1_69_0/build/lib" CACHE PATH "Path to the boost compiled binaries" FORCE)
ADD_EXECUTABLE(options options.cpp)
ADD_EXECUTABLE(any any.cpp)
TARGET_LINK_LIBRARIES(options boost_program_options)


