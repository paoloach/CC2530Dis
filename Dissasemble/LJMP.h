//
// Created by paolo on 24/03/18.
//

#ifndef CC2530DIS_LJMP_H
#define CC2530DIS_LJMP_H

#include <vector>
#include <sstream>
#include "Istr.h"

class LJMP : public HasAddress {
public:
    LJMP(std::vector<uint8_t>::iterator &istr, uint32_t pos) : HasAddress(pos) {
        std::stringstream stream;
        bytes.push_back(*istr);
        istr++;
        addr = (uint16_t) *istr << 8;
        bytes.push_back(*istr);
        istr++;
        addr += *istr;
        bytes.push_back(*istr);
        istr++;

        stream << "LJMP    " << std::setfill('0') << std::setw(4) << std::hex << (uint16_t) addr;
        toString = stream.str();
    }
};


#endif //CC2530DIS_LJMP_H
