//
// Created by paolo on 23/03/18.
//

#ifndef CC2530DIS_ACALL_H
#define CC2530DIS_ACALL_H

#include <vector>
#include <sstream>
#include "../loader/map/FlashMap.h"
#include "HasAddress.h"

class ACALL : public HasAddress {
public:
    ACALL(std::vector<uint8_t>::iterator &istr, uint32_t pos, FlashMap &flashMap) : HasAddress(pos) {
        std::stringstream stream;
        bytes.push_back(*istr);
        addr = *istr & 0xE0;
        addr = addr << 8;
        istr++;
        bytes.push_back(*istr);
        addr += *istr;
        istr++;
        auto code = flashMap.findFunction(addr);
        if (code != nullptr)
            stream << "LCALL   " << code->getName();
        else
            stream << "LCALL   " << std::setfill('0') << std::setw(4) << std::hex << (uint32_t) addr;
        toString = stream.str();
    }
};


#endif //CC2530DIS_ACALL_H
