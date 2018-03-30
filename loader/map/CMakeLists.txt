cmake_minimum_required(VERSION 3.9)
project(CC2530Dis)

SET(LOADER_SRC

        MapLoader.cpp MapLoader.h FlashMap.cpp FlashMap.cpp FlashMap.h Code.cpp Code.h XData.cpp XData.h)

add_library(map_loader_lib STATIC ${LOADER_SRC})
#target_include_directories(loader_lib PUBLIC  )
#target_link_libraries(loader_lib PUBLIC )