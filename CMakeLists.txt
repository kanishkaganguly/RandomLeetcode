cmake_minimum_required(VERSION 3.0)
project(cpp_practice)

add_compile_options(-std=c++11)
set(CMAKE_CXX_FLAGS_RELEASE "-O1")
set(CMAKE_BUILD_TYPE "Release")

file( GLOB CODE_SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp )

foreach( sourcefile ${CODE_SOURCES} )
    get_filename_component(executablename ${sourcefile} NAME_WE)
    add_executable(${executablename} ${sourcefile})
    target_link_libraries( ${executablename} )
endforeach( sourcefile ${CODE_SOURCES} )