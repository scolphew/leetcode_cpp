cmake_minimum_required(VERSION 3.19)
project(leetcode_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(leetcode_cpp main.cpp)

add_executable(788 base/base.h leetcode/_07_/_788_RotatedDigits.cpp)
add_executable(796 base/kmp.h leetcode/_07_/_796_RotateString.cpp)
add_executable(787 base/base.h leetcode/_07_/_789_EscapeTheGhosts.cpp)
add_executable(790 base/base.h leetcode/_07_/_790_DominoandTrominoTiling.cpp)
add_executable(791 base/base.h leetcode/_07_/_791_CustomSortString.cpp)
add_executable(793 base/base.h leetcode/_07_/_793_PreimageSizeofFactorialZeroesFunction.cpp)
add_executable(795 base/base.h leetcode/_07_/_795_NumberOfSubarraysWithBoundedMaximum.cpp)
