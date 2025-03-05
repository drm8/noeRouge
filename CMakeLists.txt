cmake_minimum_required(VERSION 3.15)

project(noeRouge)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall)

set(SRC_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(HEADER_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/include)

# FIXME: Fix automatically adding all files 
#file(GLOB_RECURSE SRC ${SRC_ROOT}/*.cpp)
#file(GLOB_RECURSE HEADERS ${HEADER_ROOT}/*.h)

set(INCLUDE_DIRS ${HEADER_ROOT})

add_executable(noeRouge src/main.cpp src/object.cpp src/player.cpp include/object.h include/player.h)

target_include_directories(noeRouge PRIVATE ${INCLUDE_DIRS})

if(CMAKE_BUILD_TYPE STREQUAL "debug")
    target_compile_options(noeRouge PRIVATE -Og -ggdb3 -DDEBUG)
elseif(CMAKE_BUILD_TYPE STREQUAL "release")
    target_compile_options(noeRouge PRIVATE -O3 -flto=thin)
# Custom flag to cross compile windows binary on my linux machine
elseif(CMAKE_BUILD_TYPE STREQUAL "windows")
    set(CC cl)
    set(CXX cl)
    target_compile_options(noeRouge PRIVATE -DCMAKE_SYSTEM_NAME=Windows)
endif()

target_link_libraries(noeRouge PRIVATE ${LIB})

add_custom_target(format COMMAND clang-format -i ${SRC} ${HEADERS})

