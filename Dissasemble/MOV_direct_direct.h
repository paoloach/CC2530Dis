//
// Created by paolo on 23/03/18.
//

#ifndef CC2530DIS_MOV_DIRECT_DIRECT_H
#define CC2530DIS_MOV_DIRECT_DIRECT_H

#include <vector>
#include <sstream>
#include <iostream>
#include "Istr.h"

class MOV_direct_direct : public Istr {
public:
    MOV_direct_direct(std::vector<uint8_t>::iterator &istr, uint32_t pos) : Istr(pos) {
        bytes.push_back(*istr);
        istr++;
        direct1 = *istr;
        bytes.push_back(*istr);
        istr++;
        direct2 = *istr;
        bytes.push_back(*istr);
        istr++;
        std::stringstream stream;
        stream << "MOV     " << DirectName::toString(direct2) << ","
               << DirectName::toString(direct1);
        toString = stream.str();
    }

    uint8_t direct1;
    uint8_t direct2;
};


#endif //CC2530DIS_MOV_DIRECT_DIRECT_H
