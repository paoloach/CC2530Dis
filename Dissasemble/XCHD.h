//
// Created by paolo on 23/03/18.
//

#ifndef CC2530DIS_XCHD_H
#define CC2530DIS_XCHD_H

#include <vector>
#include <sstream>
#include "Istr.h"

class XCHD : public Istr {
public:
    XCHD(std::vector<uint8_t>::iterator &istr, uint32_t pos) : Istr(pos) {
        std::stringstream stream;
        reg = *istr & 0x1;

        stream << "XCHD    A,@R" << (uint16_t) reg;
        toString = stream.str();
        bytes.push_back(*istr);
        istr++;
    }

    uint8_t reg;
};


#endif //CC2530DIS_XCHD_H
