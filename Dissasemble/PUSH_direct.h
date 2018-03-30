//
// Created by paolo on 23/03/18.
//

#ifndef CC2530DIS_PUSH_DIRECT_H
#define CC2530DIS_PUSH_DIRECT_H

#include <vector>
#include <sstream>
#include "Istr.h"

class PUSH_direct : public Istr {
public:
    PUSH_direct(std::vector<uint8_t>::iterator &istr, uint32_t pos) : Istr(pos) {
        bytes.push_back(*istr);
        istr++;
        direct = *istr;
        bytes.push_back(*istr);
        istr++;
        std::stringstream stream;
        stream << "PUSH    " << DirectName::toString(direct);
        toString = stream.str();
    }

    uint8_t direct;

};


#endif //CC2530DIS_PUSH_DIRECT_H
