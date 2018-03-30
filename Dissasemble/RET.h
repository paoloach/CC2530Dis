//
// Created by paolo on 24/03/18.
//

#ifndef CC2530DIS_RET_H
#define CC2530DIS_RET_H

#include <vector>
#include "Istr.h"

class RET : public Istr {
public:
    RET(std::vector<uint8_t>::iterator &istr, uint32_t pos) : Istr(pos) {
        toString = "RET";
        bytes.push_back(*istr);
        istr++;
    }

};


#endif //CC2530DIS_RET_H
