cmake_minimum_required (VERSION 2.6)
project (vsCmake)

message(STATUS "PROJECT_SOURCE_DIR " ${PROJECT_SOURCE_DIR})
message(STATUS "CMAKE_CURRENT_BINARY_DIR  " ${CMAKE_CURRENT_BINARY_DIR})
set(SOURCES
	vsCmake.cpp
	testadd.cpp
)
set(HEADERS
	testadd.h
)

add_executable(vsCmake ${SOURCES} ${HEADERS})
#add_precompiled_header(ffmpeg StdAfx.h FORCEINCLUDE)
configure_file("${PROJECT_SOURCE_DIR}/packages.config" "${CMAKE_CURRENT_BINARY_DIR}/packages.config")

include_directories(..)



