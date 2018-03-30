//
// Created by paolo on 23/03/18.
//

#ifndef CC2530DIS_MOV_DIRECT_DATA_H
#define CC2530DIS_MOV_DIRECT_DATA_H

#include <vector>
#include <sstream>
#include <iostream>
#include "Istr.h"

class MOV_direct_data : public Istr {
public:
    MOV_direct_data(std::vector<uint8_t>::iterator &istr, uint32_t pos) : Istr(pos) {
        bytes.push_back(*istr);
        istr++;
        direct = *istr;

        bytes.push_back(*istr);
        istr++;
        data = *istr;
        std::stringstream stream;
        stream << "MOV     " << DirectName::toString(direct) << ",#"
               << std::setfill('0') << std::setw(2) << std::hex << (uint16_t) data;
        toString = stream.str();
        bytes.push_back(*istr);
        istr++;
    }

    uint8_t direct;
    uint8_t data;
};


#endif //CC2530DIS_MOV_DIRECT_DATA_H
