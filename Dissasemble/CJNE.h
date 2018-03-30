//
// Created by paolo on 24/03/18.
//

#ifndef CC2530DIS_CJNE_H
#define CC2530DIS_CJNE_H

#include <vector>
#include "Istr.h"
#include "A_Address.h"

class CJNE : public Istr, public A_Address {
public:
    CJNE(std::vector<uint8_t>::iterator &istr, uint32_t pos) : Istr(pos) {
        std::stringstream stream;
        stream << "CJNE    ";
        addReg(stream, istr, bytes);
        addr = 3 + pos + *(std::vector<int8_t>::iterator &) istr;
        bytes.push_back(*istr);
        istr++;
        stream << "  " << std::setfill('0') << std::setw(4) << std::hex << (uint16_t) addr;
        toString = stream.str();
        bytes.push_back(*istr);
        istr++;
    }

    uint16_t addr;
};

#endif //CC2530DIS_CJNE_H
