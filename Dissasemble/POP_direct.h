//
// Created by paolo on 23/03/18.
//

#ifndef CC2530DIS_POP_DIRECT_H
#define CC2530DIS_POP_DIRECT_H

#include <vector>
#include <sstream>
#include "Istr.h"

class POP_direct : public Istr {
public:
    POP_direct(std::vector<uint8_t>::iterator &istr, uint32_t pos) : Istr(pos) {
        bytes.push_back(*istr);
        istr++;
        direct = *istr;
        bytes.push_back(*istr);
        istr++;
        std::stringstream stream;
        stream << "POP     " << DirectName::toString(direct);
        toString = stream.str();
    }

    uint8_t direct;

};

#endif //CC2530DIS_POP_DIRECT_H
