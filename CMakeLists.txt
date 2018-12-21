cmake_minimum_required(VERSION 3.13)
project(controller)

set(CMAKE_CXX_STANDARD 11)

find_package(Python3 COMPONENTS Interpreter Development)
find_package(Boost 1.60 REQUIRED COMPONENTS python3)

include_directories(${Python3_INCLUDE_DIRS})
include_directories(${Boost_INCLUDE_DIRS})

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

add_library(controller MODULE controller.cpp controller.h)
target_link_libraries(controller ${Python3_LIBRARIES} ${Boost_LIBRARIES} "-framework ApplicationServices")
set_target_properties(controller PROPERTIES PREFIX "")