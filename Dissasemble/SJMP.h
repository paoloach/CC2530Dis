//
// Created by paolo on 24/03/18.
//

#include <vector>
#include <sstream>
#include "Istr.h"

#ifndef CC2530DIS_SJMP_H
#define CC2530DIS_SJMP_H


class SJMP : public Istr {
public:
    SJMP(std::vector<uint8_t>::iterator &istr, uint32_t pos) : Istr(pos) {
        std::stringstream stream;
        bytes.push_back(*istr);
        istr++;
        addr = 2 + pos + *(std::vector<int8_t>::iterator &) (istr);
        bytes.push_back(*istr);
        istr++;
        stream << "SJMP    " << std::setfill('0') << std::setw(4) << std::hex << (uint16_t) addr;
        toString = stream.str();
    }

    uint16_t addr;
};


#endif //CC2530DIS_SJMP_H
