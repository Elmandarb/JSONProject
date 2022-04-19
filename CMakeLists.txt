cmake_minimum_required(VERSION 3.21)
project(Project3)

set(CMAKE_CXX_STANDARD 17)

add_executable(Project3 main.cpp JSONToken.cpp JSONToken.hpp JSONTokenizer.cpp JSONTokenizer.hpp JSONParser.cpp JSONParser.hpp Pair.cpp Pair.hpp EntityInstance.cpp EntityInstance.hpp EntitySet.cpp EntitySet.hpp EquityStats.cpp EquityStats.hpp)
