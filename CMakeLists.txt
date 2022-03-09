cmake_minimum_required(VERSION 3.0.0)
project(SimpleLogger VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

################################
# GTest
################################
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

################################
# Library and main app
################################
ADD_LIBRARY(SimpleLoggerLib src/StreamLoggerWriter.cpp src/SimpleLogger.cpp)

ADD_EXECUTABLE(SimpleLogger main.cpp)
TARGET_LINK_LIBRARIES(SimpleLogger SimpleLoggerLib)

################################
# Unit Tests
################################
# Add test cpp file
add_executable( runUnitTests tests/unitTests.cpp )
# Link test executable against gtest & gtest_main & library
target_link_libraries(runUnitTests gtest gtest_main SimpleLoggerLib)
add_test( runUnitTests runUnitTests )





set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
