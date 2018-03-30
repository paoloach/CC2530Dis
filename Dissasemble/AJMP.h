//
// Created by paolo on 24/03/18.
//

#ifndef CC2530DIS_AJMP_H
#define CC2530DIS_AJMP_H

#include <vector>
#include <sstream>
#include "Istr.h"
#include "HasAddress.h"

class AJMP : public HasAddress {
public:
    AJMP(std::vector<uint8_t>::iterator &istr, uint32_t pos) : HasAddress(pos) {
        std::stringstream stream;
        addr = *istr & 0xE0;
        addr = addr << 8;
        bytes.push_back(*istr);
        istr++;
        addr += *istr;
        bytes.push_back(*istr);
        istr++;

        stream << "AJMP    " << std::setfill('0') << std::setw(4) << std::hex << (uint16_t) addr;
        toString = stream.str();
    }

    uint16_t addr;

};


#endif //CC2530DIS_AJMP_H
