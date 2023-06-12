cmake_minimum_required(VERSION 3.0.0)
project(lab6 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Floyd_sort Floyd_sort.cpp)
add_executable(Patience_sort Patience_sort.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
