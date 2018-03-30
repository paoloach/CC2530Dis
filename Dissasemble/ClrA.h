//
// Created by paolo on 22/03/18.
//

#ifndef CC2530DIS_CLRA_H
#define CC2530DIS_CLRA_H


#include <vector>
#include "Istr.h"

class ClrA : public Istr {
public:
    ClrA(std::vector<uint8_t>::iterator &istr, uint32_t pos) : Istr(pos) {
        bytes.push_back(*istr);
        istr++;
        toString = "CLR     A";
    }

};


#endif //CC2530DIS_CLRA_H
