CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
project(spirit)
LINK_DIRECTORIES("${boost_lib_dir}")
INCLUDE_DIRECTORIES("/home/pat/boost_1_69_0")
ADD_EXECUTABLE(listVector listToVectorParser.cpp)

