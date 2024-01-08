cmake_minimum_required(VERSION 3.0)

project(LinearAlgebruh)

set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# build standard LA library for general usage
set(STD_SRC
    src/la.cpp
)
add_library(la STATIC ${STD_SRC})
target_include_directories(la PUBLIC include)

# build extended LA library for 3D/OpenGL usage
set(EXT_SRC
    ${STD_SRC}
    src/la_extended.cpp
)
add_library(lagl STATIC ${EXT_SRC})
target_include_directories(lagl PUBLIC include)
