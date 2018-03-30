//
// Created by paolo on 23/03/18.
//

#ifndef CC2530DIS_MOV_DPTR_A_H
#define CC2530DIS_MOV_DPTR_A_H

#include <vector>
#include <sstream>
#include <iostream>
#include "Istr.h"

class MOV_DPTR_data : public Istr {
public:
    MOV_DPTR_data(std::vector<uint8_t>::iterator &istr, uint32_t pos) : Istr(pos) {
        reg = (*istr) & 0x01;
        bytes.push_back(*istr);
        istr++;
        data = *istr;
        data = data << 8;
        bytes.push_back(*istr);
        istr++;
        data |= *istr;
        bytes.push_back(*istr);
        istr++;
        std::stringstream stream;
        stream << "MOV     DPTR,#" << std::setfill('0') << std::setw(4) << std::hex << (uint16_t) data;
        toString = stream.str();
    }

    uint8_t reg;
    uint16_t data;

};


#endif //CC2530DIS_MOV_DPTR_A_H
