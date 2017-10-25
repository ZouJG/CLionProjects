cmake_minimum_required(VERSION 3.8)
project(maskcoreSO)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp MaskFunction.h ChMask.h ChMask.cpp)
add_executable(maskcoreSO ${SOURCE_FILES})
target_link_libraries(maskcoreSO ${CMAKE_DL_LIBS})