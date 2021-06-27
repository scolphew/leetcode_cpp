cmake_minimum_required(VERSION 3.19)
project(leetcode_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(leetcode_cpp main.cpp)

add_executable(788 leetcode/_07_/_788_RotatedDigits.cpp)
add_executable(796 base/kmp.h leetcode/_07_/_796_RotateString.cpp)
