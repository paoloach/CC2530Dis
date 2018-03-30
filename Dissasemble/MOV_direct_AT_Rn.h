//
// Created by paolo on 23/03/18.
//

#ifndef CC2530DIS_MOV_DIRECT_AT_RN_H
#define CC2530DIS_MOV_DIRECT_AT_RN_H

#include <vector>
#include <sstream>
#include <iostream>
#include "Istr.h"

class MOV_direct_AT_Rn : public Istr {
public:
    MOV_direct_AT_Rn(std::vector<uint8_t>::iterator &istr, uint32_t pos) : Istr(pos) {
        reg = (*istr) & 0x01;
        bytes.push_back(*istr);
        istr++;
        direct = *istr;
        bytes.push_back(*istr);
        istr++;
        std::stringstream stream;
        stream << "MOV     " << std::setfill('0') << std::setw(2) << std::hex << (uint16_t) direct << ",@R"
               << (uint16_t) reg;
        toString = stream.str();
    }

    uint8_t reg;
    uint8_t direct;
};


#endif //CC2530DIS_MOV_DIRECT_AT_RN_H
