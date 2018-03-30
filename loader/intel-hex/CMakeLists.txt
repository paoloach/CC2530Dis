cmake_minimum_required(VERSION 3.9)
project(CC2530Dis)

SET(LOADER_SRC
        HexLine.cpp HexLine.h
        IntelEndOfFile.cpp IntelEndOfFile.h
        IntelHexData.cpp IntelHexData.h
        IntelHexExtendedLinearAddress.cpp IntelHexExtendedLinearAddress.h
        IntelHexInvalidLine.cpp IntelHexInvalidLine.h
        IntelHexLine.cpp IntelHexLine.h
        IntelHexLoader.cpp IntelHexLoader.h
        IntelHexStartLinearAddress.cpp IntelHexStartLinearAddress.h
        ../../Exceptions/InvalidIntelHexFile.h
        )

add_library(intel_hex_loader_lib STATIC ${LOADER_SRC})
#target_include_directories(loader_lib PUBLIC  )
#target_link_libraries(loader_lib PUBLIC )