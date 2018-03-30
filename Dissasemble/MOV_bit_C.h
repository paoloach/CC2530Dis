//
// Created by paolo on 24/03/18.
//

#ifndef CC2530DIS_MOV_BIT_C_H
#define CC2530DIS_MOV_BIT_C_H


#include <vector>
#include <sstream>
#include "Istr.h"

class MOV_bit_C : public Istr {
public:
    MOV_bit_C(std::vector<uint8_t>::iterator &istr, uint32_t pos) : Istr(pos) {
        std::stringstream stream;
        bytes.push_back(*istr);
        istr++;
        bit = *istr;
        stream << "MOV     " << std::setfill('0') << std::setw(2) << std::hex << (uint16_t) bit << ",C";
        bytes.push_back(*istr);
        istr++;
    }

    uint8_t bit;

};


#endif //CC2530DIS_MOV_BIT_C_H
