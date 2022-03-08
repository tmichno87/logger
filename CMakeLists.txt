cmake_minimum_required(VERSION 3.0.0)
project(SimpleLogger VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#------------------------------------------------------------------------------
ADD_LIBRARY(SimpleLoggerLib src/StreamLoggerWriter.cpp src/SimpleLogger.cpp)

ADD_EXECUTABLE(SimpleLogger main.cpp)
TARGET_LINK_LIBRARIES(SimpleLogger SimpleLoggerLib)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
