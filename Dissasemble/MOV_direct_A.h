//
// Created by paolo on 23/03/18.
//

#ifndef CC2530DIS_MOV_DIRECT_A_H
#define CC2530DIS_MOV_DIRECT_A_H

#include <vector>
#include <sstream>
#include <iostream>
#include "Istr.h"


class MOV_direct_A : public Istr {
public:
    MOV_direct_A(std::vector<uint8_t>::iterator &istr, uint32_t pos) : Istr(pos) {
        bytes.push_back(*istr);
        istr++;
        direct = *istr;
        bytes.push_back(*istr);
        istr++;
        std::stringstream stream;
        stream << "MOV     " << DirectName::toString(direct) << ",A";
        toString = stream.str();
    }

    uint8_t reg;
    uint8_t direct;
};


#endif //CC2530DIS_MOV_DIRECT_A_H
