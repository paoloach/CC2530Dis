//
// Created by paolo on 23/03/18.
//

#ifndef CC2530DIS_LCALL_H
#define CC2530DIS_LCALL_H


#include <vector>
#include <sstream>

#include "../loader/map/FlashMap.h"
#include "HasAddress.h"

class LCALL :  public HasAddress {
public:
    LCALL(std::vector<uint8_t>::iterator &istr, uint32_t pos, FlashMap & flashMap) : HasAddress(pos) {
        bytes.push_back(*istr);
        std::stringstream stream;
        istr++;
        addr = (uint16_t )*istr << 8;
        bytes.push_back(*istr);
        istr++;
        addr += *istr;
        bytes.push_back(*istr);
        istr++;
        auto code = flashMap.findFunction(addr);
        if (code != nullptr)
            stream << "LCALL   " << code->getName();
        else
            stream << "LCALL   " << std::setfill('0') << std::setw(4) << std::hex << (uint16_t) addr;
        toString = stream.str();
    }
};


#endif //CC2530DIS_LCALL_H
