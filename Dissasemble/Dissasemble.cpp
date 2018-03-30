//
// Created by paolo on 21/03/18.
//

#include <iostream>
#include <iomanip>
#include "Dissasemble.h"
#include "AddRn.h"
#include "AddADirect.h"
#include "AddAIndirect.h"
#include "AddCRn.h"
#include "AddAData.h"
#include "AddACIndirect.h"
#include "AddACData.h"
#include "Subb.h"
#include "Inc.h"
#include "Dec.h"
#include "MulAB.h"
#include "DivAB.h"
#include "DA.h"
#include "Logical.h"
#include "ClrA.h"
#include "CplA.h"
#include "R_A.h"
#include "MOV_A.h"
#include "MOV_A_Data.h"
#include "MOV_Rn_A.h"
#include "MOV_Rn_direct.h"
#include "MOV_Rn_data.h"
#include "MOV_direct_A.h"
#include "MOV_direct_Rn.h"
#include "MOV_direct_direct.h"
#include "MOV_direct_AT_Rn.h"
#include "MOV_direct_data.h"
#include "MOV_AT_RN_A.h"
#include "MOV_At_Rn_direct.h"
#include "MOV_At_Rn_data.h"
#include "MOV_DPTR_data.h"
#include "MOVC.h"
#include "MOVX.h"
#include "PUSH_direct.h"
#include "POP_direct.h"
#include "XCH.h"
#include "XCHD.h"
#include "ACALL.h"
#include "LCALL.h"
#include "RET.h"
#include "RETI.h"
#include "AJMP.h"
#include "LJMP.h"
#include "SJMP.h"
#include "BIT_C.h"
#include "JMP_AT.h"
#include "JCOND.h"
#include "CJNE.h"
#include "DJNZ.h"
#include "NOP.h"
#include "Logic_Bit.h"
#include "MOV_C_bit.h"
#include "MOV_bit_C.h"

std::unique_ptr<Function> Dissasemble::dissasemble(std::vector<uint8_t> &memory, FlashMap &flashMap, Code *code,
                                                   FunctionsDone &functionDone) {
    auto result = std::make_unique<Function>(code->getName(), code->start, code->end);
    auto iter = memory.begin() + code->start;
    auto end = memory.begin() + code->end;
    std::cout << "Parsing: " << code->getName() << std::hex << "[" << code->start << " - " << code->end << "]" << std::endl;
    while (iter <= end) {
        uint32_t pos = iter - memory.begin();
        switch (*iter) {
            case 0x00:
                result->instrs.push_back(std::make_unique<NOP>(iter, pos));
                break;
            case 0x01:
                result->instrs.push_back(std::make_unique<AJMP>(iter, pos));
                break;
            case 0x02:
                result->instrs.push_back(std::make_unique<LJMP>(iter, pos));
                break;
            case 0x03:
                result->instrs.push_back(std::make_unique<R_A>(iter, pos));
                break;
            case 0x04 ... 0x0F:
                result->instrs.push_back(std::make_unique<Inc>(iter, pos));
                break;
            case 0x10:
                result->instrs.push_back(std::make_unique<JCOND>(iter, pos));
                break;
            case 0x11:
                result->instrs.push_back(std::make_unique<ACALL>(iter, pos, flashMap));
                break;
            case 0x12:
                result->instrs.push_back(std::make_unique<LCALL>(iter, pos, flashMap));
                break;
            case 0x13:
                result->instrs.push_back(std::make_unique<R_A>(iter, pos));
                break;
            case 0x14 ... 0x1F:
                result->instrs.push_back(std::make_unique<Dec>(iter, pos));
                break;
            case 0x20:
                result->instrs.push_back(std::make_unique<JCOND>(iter, pos));
                break;
            case 0x21:
                result->instrs.push_back(std::make_unique<AJMP>(iter, pos));
                break;
            case 0x22:
                result->instrs.push_back(std::make_unique<RET>(iter, pos));
                break;
            case 0x23:
                result->instrs.push_back(std::make_unique<R_A>(iter, pos));
                break;
            case 0x24:
                result->instrs.push_back(std::make_unique<AddAData>(iter, pos));
                break;
            case 0x25:
                result->instrs.push_back(std::make_unique<AddADirect>(iter, pos));
                break;
            case 0x26:
            case 0x27:
                result->instrs.push_back(std::make_unique<AddAIndirect>(iter, pos));
                break;
            case 0x28 ... 0x02F:
                result->instrs.push_back(std::make_unique<AddRn>(iter, pos));
                break;
            case 0x30:
                result->instrs.push_back(std::make_unique<JCOND>(iter, pos));
                break;
            case 0x31:
                result->instrs.push_back(std::make_unique<ACALL>(iter, pos, flashMap));
                break;
            case 0x32:
                result->instrs.push_back(std::make_unique<RETI>(iter, pos));
                break;
            case 0x33:
                result->instrs.push_back(std::make_unique<R_A>(iter, pos));
                break;
            case 0x34:
                result->instrs.push_back(std::make_unique<AddACData>(iter, pos));
                break;
            case 0x35:
                result->instrs.push_back(std::make_unique<AddACIndirect>(iter, pos));
                break;
            case 0x36:
            case 0x37:
                result->instrs.push_back(std::make_unique<AddACIndirect>(iter, pos));
                break;
            case 0x38 ... 0x3F:
                result->instrs.push_back(std::make_unique<AddCRn>(iter, pos));
                break;
            case 0x40:
                result->instrs.push_back(std::make_unique<JCOND>(iter, pos));
                break;
            case 0x41:
                result->instrs.push_back(std::make_unique<AJMP>(iter, pos));
                break;
            case 0x42 ... 0x4F:
                result->instrs.push_back(std::make_unique<Logical>(iter, pos, "ORL     "));
                break;
            case 0x50:
                result->instrs.push_back(std::make_unique<JCOND>(iter, pos));
                break;
            case 0x51:
                result->instrs.push_back(std::make_unique<ACALL>(iter, pos, flashMap));
                break;
            case 0x52 ... 0x5F:
                result->instrs.push_back(std::make_unique<Logical>(iter, pos, "ANL     "));
                break;
            case 0x60:
                result->instrs.push_back(std::make_unique<JCOND>(iter, pos));
                break;
            case 0x61:
                result->instrs.push_back(std::make_unique<AJMP>(iter, pos));
                break;
            case 0x62 ... 0x6F:
                result->instrs.push_back(std::make_unique<Logical>(iter, pos, "XRL     "));
                break;
            case 0x70:
                result->instrs.push_back(std::make_unique<JCOND>(iter, pos));
                break;
            case 0x71:
                result->instrs.push_back(std::make_unique<ACALL>(iter, pos, flashMap));
                break;
            case 0x72:
                result->instrs.push_back(std::make_unique<Logic_Bit>(iter, pos));
                break;
            case 0x73:
                result->instrs.push_back(std::make_unique<JMP_AT>(iter, pos));
                break;
            case 0x74:
                result->instrs.push_back(std::make_unique<MOV_A_Data>(iter, pos));
                break;
            case 0x75:
                result->instrs.push_back(std::make_unique<MOV_direct_data>(iter, pos));
                break;
            case 0x76:
            case 0x77:
                result->instrs.push_back(std::make_unique<MOV_At_Rn_data>(iter, pos));
                break;
            case 0x78 ... 0x7F:
                result->instrs.push_back(std::make_unique<MOV_Rn_data>(iter, pos));
                break;
            case 0x80:
                result->instrs.push_back(std::make_unique<SJMP>(iter, pos));
                break;
            case 0x81:
                result->instrs.push_back(std::make_unique<AJMP>(iter, pos));
                break;
            case 0x82:
                result->instrs.push_back(std::make_unique<Logic_Bit>(iter, pos));
                break;
            case 0x83:
                result->instrs.push_back(std::make_unique<MOVC>(iter, pos));
                break;
            case 0x84:
                result->instrs.push_back(std::make_unique<DivAB>(iter, pos));
                break;
            case 0x85:
                result->instrs.push_back(std::make_unique<MOV_direct_direct>(iter, pos));
                break;
            case 0x86:
            case 0x87:
                result->instrs.push_back(std::make_unique<MOV_direct_AT_Rn>(iter, pos));
                break;
            case 0x88 ... 0x8F:
                result->instrs.push_back(std::make_unique<MOV_direct_Rn>(iter, pos));
                break;
            case 0x90:
                result->instrs.push_back(std::make_unique<MOV_DPTR_data>(iter, pos));
                break;
            case 0x91:
                result->instrs.push_back(std::make_unique<ACALL>(iter, pos, flashMap));
                break;
            case 0x92:
                result->instrs.push_back(std::make_unique<MOV_bit_C>(iter, pos));
                break;
            case 0x93:
                result->instrs.push_back(std::make_unique<MOVC>(iter, pos));
                break;
            case 0x94 ... 0x9F:
                result->instrs.push_back(std::make_unique<Subb>(iter, pos));
                break;
            case 0xA0:
                result->instrs.push_back(std::make_unique<Logic_Bit>(iter, pos));
                break;
            case 0xA1:
                result->instrs.push_back(std::make_unique<AJMP>(iter, pos));
                break;
            case 0xA2:
                result->instrs.push_back(std::make_unique<MOV_C_bit>(iter, pos));
                break;
            case 0xA3:
                result->instrs.push_back(std::make_unique<Inc>(iter, pos));
                break;
            case 0xA4:
                result->instrs.push_back(std::make_unique<MulAB>(iter, pos));
                break;
            case 0xA6:
            case 0xA7:
                result->instrs.push_back(std::make_unique<MOV_At_Rn_direct>(iter, pos));
                break;
            case 0xA8 ... 0xAF:
                result->instrs.push_back(std::make_unique<MOV_Rn_direct>(iter, pos));
                break;
            case 0xB0:
                result->instrs.push_back(std::make_unique<Logic_Bit>(iter, pos));
                break;
            case 0xB1:
                result->instrs.push_back(std::make_unique<ACALL>(iter, pos, flashMap));
                break;
            case 0xB2:
            case 0xB3:
                result->instrs.push_back(std::make_unique<BIT_C>(iter, pos));
                break;
            case 0xB4 ... 0xBF:
                result->instrs.push_back(std::make_unique<CJNE>(iter, pos));
                break;
            case 0xC0:
                result->instrs.push_back(std::make_unique<PUSH_direct>(iter, pos));
                break;
            case 0xC1:
                result->instrs.push_back(std::make_unique<AJMP>(iter, pos));
                break;
            case 0xC2:
            case 0xC3:
                result->instrs.push_back(std::make_unique<BIT_C>(iter, pos));
                break;
            case 0xC5 ... 0xCF:
                result->instrs.push_back(std::make_unique<XCH>(iter, pos));
                break;
            case 0xD0:
                result->instrs.push_back(std::make_unique<POP_direct>(iter, pos));
                break;
            case 0xD1:
                result->instrs.push_back(std::make_unique<ACALL>(iter, pos, flashMap));
                break;
            case 0xD2:
            case 0xD3:
                result->instrs.push_back(std::make_unique<BIT_C>(iter, pos));
                break;
            case 0xD4:
                result->instrs.push_back(std::make_unique<DJNZ>(iter, pos));
                break;
            case 0xD5:
                result->instrs.push_back(std::make_unique<DA>(iter, pos));
                break;
            case 0xD6:
            case 0xD7:
                result->instrs.push_back(std::make_unique<XCHD>(iter, pos));
                break;
            case 0xD8 ... 0xDF:
                result->instrs.push_back(std::make_unique<DJNZ>(iter, pos));
                break;
            case 0xE0:
                result->instrs.push_back(std::make_unique<MOVX>(iter, pos));
                break;
            case 0xE1:
                result->instrs.push_back(std::make_unique<AJMP>(iter, pos));
                break;
            case 0xE2:
            case 0xE3:
                result->instrs.push_back(std::make_unique<MOVX>(iter, pos));
                break;
            case 0xE4:
                result->instrs.push_back(std::make_unique<ClrA>(iter, pos));
                break;
            case 0xE5 ... 0xEF:
                result->instrs.push_back(std::make_unique<MOV_A>(iter, pos));
                break;
            case 0xF0:
                result->instrs.push_back(std::make_unique<MOVX>(iter, pos));
                break;
            case 0xF1:
                result->instrs.push_back(std::make_unique<ACALL>(iter, pos, flashMap));
                break;
            case 0xF2:
            case 0xF3:
                result->instrs.push_back(std::make_unique<MOVX>(iter, pos));
                break;
            case 0xF4:
                result->instrs.push_back(std::make_unique<CplA>(iter, pos));
                break;
            case 0xF5:
                result->instrs.push_back(std::make_unique<MOV_direct_A>(iter, pos));
                break;
            case 0xF6:
            case 0xF7:
                result->instrs.push_back(std::make_unique<MOV_AT_RN_A>(iter, pos));
                break;
            case 0xF8 ... 0xFF:
                result->instrs.push_back(std::make_unique<MOV_Rn_A>(iter, pos));
                break;

            default:
                iter++;
        }
    }
    auto function = result.get();

    for (auto &istr: function->instrs) {
        auto hasAddress = dynamic_cast<HasAddress *>(istr.get());
        if (hasAddress != nullptr) {
            auto childCode = flashMap.findFunction(hasAddress->addr);
            if (childCode != nullptr) {
                auto functionName = childCode->getName();
                if (functionName.length() > 8) {
                    auto tail = functionName.substr(functionName.length() - 8, 8);
                    if (tail == "::?relay") {
                        functionName = functionName.substr(0, functionName.length() - 8);
                        auto realCode = flashMap.findFunction(functionName);
                        if (realCode != nullptr)
                            childCode = realCode;
                    }
                }
                if (functionDone.count(childCode->getName()) == 0) {
                    functionDone[childCode->getName()] = std::unique_ptr<Function>();
                    functionDone[childCode->getName()] = dissasemble(memory, flashMap, childCode, functionDone);
                }
                function->called.insert(functionDone[childCode->getName()].get());
            }
        }
    }


    return result;
}
