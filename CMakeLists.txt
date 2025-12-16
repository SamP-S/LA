cmake_minimum_required(VERSION 3.8)

project(LinearAlgebruh LANGUAGES CXX)

set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# linear algebra library
file(GLOB_RECURSE SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/**.cpp")
set(INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/include")
add_library(la STATIC ${SRC_FILES})
target_include_directories(la PUBLIC ${INCLUDE_DIRS})
