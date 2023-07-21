cmake_minimum_required(VERSION 3.0.0)

project(nsodium CXX)

include_directories(${CMAKE_JS_INC})
include_directories(${NODE_ADDON_INC})

add_library(nsodium SHARED "native/index.cpp")

target_link_libraries(nsodium sodium ${CMAKE_JS_LIB})
set_target_properties(nsodium PROPERTIES PREFIX "" SUFFIX ".node")