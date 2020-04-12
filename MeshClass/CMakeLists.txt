cmake_minimum_required(VERSION 3.8)
project(mesh)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

###############################################
### For debug mode                          ###
###############################################
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -fopenmp -O2")


###############################################
### For release mode                        ###
###############################################
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O3 -march=native -DNDEBUG")




#############################################################
#############################################################
set(src main.cpp)

#############################################################
### for mesh and its extension
#############################################################
set(src ${src} include/MeshBase.h)
set(src ${src} include/MeshBulk.h)
set(src ${src} src/MeshBulk.cpp src/CreateBulkMesh.cpp)

set(src ${src} include/MeshInterface.h src/MeshInterface.cpp)
set(src ${src} src/CreateInterfaceMesh.cpp)

set(src ${src} include/Mesh.h)
##################################################
add_executable(mesh ${src})

