//
// Created by paolo on 23/03/18.
//

#ifndef CC2530DIS_MOV_AT_RN_DATA_H
#define CC2530DIS_MOV_AT_RN_DATA_H

#include <vector>
#include <sstream>
#include <iostream>
#include "Istr.h"

class MOV_At_Rn_data : public Istr {
public:
    MOV_At_Rn_data(std::vector<uint8_t>::iterator &istr, uint32_t pos) : Istr(pos) {
        reg = (*istr) & 0x01;
        bytes.push_back(*istr);
        istr++;
        data = *istr;
        bytes.push_back(*istr);
        istr++;
        std::stringstream stream;
        stream << "MOV     @R" << reg << ",#" << std::setfill('0') << std::setw(2) << std::hex << (uint16_t) data;
        toString = stream.str();
    }

    uint8_t reg;
    uint8_t data;
};


#endif //CC2530DIS_MOV_AT_RN_DATA_H
