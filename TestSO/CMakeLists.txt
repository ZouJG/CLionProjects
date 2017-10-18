cmake_minimum_required(VERSION 3.8)
project(TestSO)

set(CMAKE_CXX_STANDARD 11)
set(LIBS=-ldl CFLAGS=-fno-strict-aliasing)

set(SOURCE_FILES main.cpp TestMath.h FuncChoose.h FuncChoose.cpp)
add_executable(TestSO ${SOURCE_FILES})
target_link_libraries(TestSO ${CMAKE_DL_LIBS})
