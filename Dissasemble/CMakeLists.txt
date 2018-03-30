cmake_minimum_required(VERSION 3.9)
project(CC2530Dis)

add_library(dissasemble_lib STATIC
        Dissasemble.cpp
        Dissasemble.h
        Function.cpp Function.h
        Istr.cpp Istr.h
        AddRn.cpp AddRn.h
        AddADirect.h AddAIndirect.h AddCRn.h AddAData.h AddACIndirect.h AddCDirect.h AddACData.h
        Subb.cpp Subb.h
        Inc.cpp Inc.h IncDecReg.cpp IncDecReg.h Dec.cpp Dec.h MulAB.h DivAB.h DA.h
        Logical.cpp Logical.h ClrA.h CplA.h R_A.cpp R_A.h MOV_A.cpp MOV_A.h A_Address.cpp A_Address.h
        MOV_A_Data.h MOV_Rn_A.h MOV_Rn_direct.h MOV_Rn_data.h MOV_direct_A.h MOV_direct_Rn.h MOV_direct_direct.h
        MOV_direct_AT_Rn.h MOV_direct_data.h MOV_AT_RN_A.h MOV_At_Rn_direct.h MOV_At_Rn_data.h MOV_DPTR_data.h
        MOVC.h MOVX.h PUSH_direct.h POP_direct.h XCH.h XCHD.h ACALL.h LCALL.h DirectName.cpp DirectName.h
        RET.h RETI.h
        AJMP.h LJMP.h SJMP.h BIT_C.h JMP_AT.h JCOND.h CJNE.h DJNZ.h NOP.h
        Logic_Bit.h MOV_C_bit.h MOV_bit_C.h HasAddress.h)
#target_include_directories(loader_lib PUBLIC  )
#target_link_libraries(loader_lib PUBLIC )