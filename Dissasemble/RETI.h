//
// Created by paolo on 24/03/18.
//

#ifndef CC2530DIS_RETI_H
#define CC2530DIS_RETI_H

#include <vector>
#include "Istr.h"

class RETI : public Istr {
public:
    RETI(std::vector<uint8_t>::iterator &istr, uint32_t pos) : Istr(pos) {
        toString = "RETI";
        bytes.push_back(*istr);
        istr++;
    }

};


#endif //CC2530DIS_RETI_H
