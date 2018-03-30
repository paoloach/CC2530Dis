//
// Created by paolo on 23/03/18.
//

#ifndef CC2530DIS_MOV_A_DATA_H
#define CC2530DIS_MOV_A_DATA_H

#include <vector>
#include <sstream>
#include <iomanip>
#include "Istr.h"

class MOV_A_Data : public Istr {
public:
    MOV_A_Data(std::vector<uint8_t>::iterator &istr, uint32_t pos) : Istr(pos) {
        bytes.push_back(*istr);
        istr++;
        data = *istr;
        bytes.push_back(*istr);
        istr++;
        std::stringstream stream;
        stream << "MOV     A,#" << std::setfill('0') << std::setw(2) << std::hex << (uint16_t) data;
        toString = stream.str();

    }

    uint8_t data;
};


#endif //CC2530DIS_MOV_A_DATA_H
