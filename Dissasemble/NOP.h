//
// Created by paolo on 24/03/18.
//

#ifndef CC2530DIS_NOP_H
#define CC2530DIS_NOP_H

#include <vector>
#include "Istr.h"

class NOP : public Istr {
public:
    NOP(std::vector<uint8_t>::iterator &istr, uint32_t pos) : Istr(pos) {
        bytes.push_back(*istr);
        toString = "NOP";
        istr++;
    }
};


#endif //CC2530DIS_NOP_H
