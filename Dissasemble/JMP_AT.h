//
// Created by paolo on 24/03/18.
//

#ifndef CC2530DIS_JMP_AT_H
#define CC2530DIS_JMP_AT_H

#include <vector>
#include <sstream>
#include "Istr.h"
class JMP_AT : public HasAddress {
public:
    JMP_AT(std::vector<uint8_t>::iterator &istr, uint32_t pos) : HasAddress(pos) {
        bytes.push_back(*istr);
        istr++;
        toString = "JMP     @A+DPTR";
    }
};


#endif //CC2530DIS_JMP_AT_H
