cmake_minimum_required(VERSION 3.19)
set(CMAKE_CXX_STANDARD 20)
set(PROJECT_NAME gruzovik)

project(${PROJECT_NAME})
set(CMAKE_CXX_STANDARD 20)
include(GNUInstallDirs)

add_executable(${PROJECT_NAME} gruzovik.cpp)
