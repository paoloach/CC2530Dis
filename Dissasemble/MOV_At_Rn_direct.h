//
// Created by paolo on 23/03/18.
//

#ifndef CC2530DIS_MOV_AT_RN_DIRECT_H
#define CC2530DIS_MOV_AT_RN_DIRECT_H

#include <vector>
#include <sstream>
#include <iostream>
#include "Istr.h"

class MOV_At_Rn_direct : public Istr {
public:
    MOV_At_Rn_direct(std::vector<uint8_t>::iterator &istr, uint32_t pos) : Istr(pos) {
        reg = (*istr) & 0x01;
        bytes.push_back(*istr);
        istr++;
        direct = *istr;
        bytes.push_back(*istr);
        istr++;
        std::stringstream stream;
        stream << "MOV     @R" << (uint16_t) reg << "," << DirectName::toString(direct);
        toString = stream.str();
    }

    uint8_t reg;
    uint8_t direct;
};


#endif //CC2530DIS_MOV_AT_RN_DIRECT_H
