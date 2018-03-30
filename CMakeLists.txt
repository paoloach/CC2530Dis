cmake_minimum_required(VERSION 3.9)
project(CC2530Dis)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost 1.63 COMPONENTS date_time program_options log REQUIRED)
add_subdirectory(loader/intel-hex)
add_subdirectory(loader/map)
add_subdirectory(Dissasemble)

add_executable(CC2530Dis main.cpp Decoder.cpp Decoder.h )

target_link_libraries(CC2530Dis
        Boost::program_options
        intel_hex_loader_lib
        map_loader_lib
        dissasemble_lib
        )

