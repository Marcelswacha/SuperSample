cmake_minimum_required(VERSION 2.8)
find_package(CUDA REQUIRED)

LIST(APPEND CMAKE_CXX_FLAGS "-std=c++11 -O3 -ffast-math -Wall -pthread")

LIST(APPEND CUDA_NVCC_FLAGS --compiler-options -fno-strict-aliasing -lineinfo -use_fast_math -Xptxas -dlcm=cg)

LIST(APPEND CUDA_NVCC_FLAGS -gencode arch=compute_35,code=sm_35)

SET(CUDA_PROPAGATE_HOST_FLAGS OFF)

include_directories(
    utility
    )

cuda_add_executable(
    hellocuda
	main.cpp
    utility/hello.h
	utility/hello.cu
    )

target_link_libraries(
	hellocuda
	)
