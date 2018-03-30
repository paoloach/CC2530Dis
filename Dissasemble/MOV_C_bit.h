//
// Created by paolo on 24/03/18.
//

#ifndef CC2530DIS_MOV_C_BIT_H
#define CC2530DIS_MOV_C_BIT_H


#include <vector>
#include <sstream>
#include "Istr.h"

class MOV_C_bit : public Istr {
public:
    MOV_C_bit(std::vector<uint8_t>::iterator &istr, uint32_t pos) : Istr(pos) {
        std::stringstream stream;
        bytes.push_back(*istr);
        istr++;
        bit = *istr;
        stream << "MOV     C," << DirectName::bitToString(bit);
        bytes.push_back(*istr);
        istr++;
        toString = stream.str();
    }

    uint8_t bit;

};


#endif //CC2530DIS_MOV_C_BIT_H
