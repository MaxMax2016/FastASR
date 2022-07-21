cmake_minimum_required(VERSION 3.10)

set (CMAKE_CXX_STANDARD 11)

# OPTION (USE_OpenMP "Use OpenMP" ON)
# IF(USE_OpenMP)
#     FIND_PACKAGE(OpenMP)
#     IF(OPENMP_FOUND)
#         SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
#         SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
#     ENDIF()
# ENDIF()
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fopenmp")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")

project(FastASR)



add_subdirectory(lib)
add_subdirectory(examples)
