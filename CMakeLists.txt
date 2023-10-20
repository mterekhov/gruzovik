cmake_minimum_required(VERSION 3.19)
set(CMAKE_CXX_STANDARD 20)
set(PROJECT_NAME gruzovik)

project(${PROJECT_NAME})
set(CMAKE_CXX_STANDARD 20)
include(GNUInstallDirs)

#   MACOSX
if(APPLE)
	include_directories(/opt/homebrew/opt/fastcgi/include)	
	set(CMAKE_PREFIX_PATH /opt/homebrew/opt/fastcgi/lib)
endif()

#   FreeBSD
if(UNIX AND NOT APPLE)
	include_directories(/usr/local/include)
endif()

find_library(FCGI_LIB fcgi lib)
find_library(FCGI_LIB++ fcgi++ lib)
add_executable(${PROJECT_NAME} gruzovik.cpp)
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC ${FCGI_LIB} ${FCGI_LIB++})
