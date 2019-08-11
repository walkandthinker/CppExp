cmake_minimum_required(VERSION 3.8)
project(perftest)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

###############################################
### For debug mode                          ###
###############################################
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -fopenmp -O2")


###############################################
### For release mode                        ###
###############################################
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O3 -march=native -DNDEBUG")




#############################################################
#############################################################
set(src main.cpp Vector2D.h Array2D.h)






##################################################
add_executable(perftest ${src})

