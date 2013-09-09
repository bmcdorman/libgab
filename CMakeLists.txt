project(libgab)
cmake_minimum_required(VERSION 2.8)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(TEST_DIR ${CMAKE_SOURCE_DIR}/test)

file(GLOB SOURCES ${SRC_DIR}/*.cpp)

include_directories(${INCLUDE_DIR})

set(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++")
add_definitions(-g -pg)

add_library(gab SHARED ${SOURCES})
target_link_libraries(gab tinyxml)

add_subdirectory(${TEST_DIR})

install(TARGETS gab LIBRARY DESTINATION lib)
install(DIRECTORY ${INCLUDE_DIR}/gab DESTINATION include)