//
// Created by paolo on 23/03/18.
//

#ifndef CC2530DIS_MOVX_H
#define CC2530DIS_MOVX_H

#include <vector>
#include <sstream>
#include <iostream>
#include "Istr.h"

class MOVX : public Istr {
public:
    MOVX(std::vector<uint8_t>::iterator &istr, uint32_t pos) : Istr(pos) {
        swap = (*istr) & 0x10;
        dptr = (*istr) & 0x03;
        bytes.push_back(*istr);
        istr++;
        std::stringstream stream;
        stream << "MOVX    ";
        if (swap) {
            if (dptr == 0) {
                stream << "@DPTR,A";
            } else {
                stream << "@R" << (uint16_t) (dptr >> 1) << ",A";
            }
        } else {
            if (dptr == 0) {
                stream << "A,@DPTR";
            } else {
                stream << "A,@R" << (uint16_t) (dptr >> 1);
            }
        }

        toString = stream.str();
    }

    bool dptr;
    bool swap;
    uint8_t data;
};


#endif //CC2530DIS_MOVX_H
