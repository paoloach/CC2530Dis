//
// Created by paolo on 22/03/18.
//

#ifndef CC2530DIS_DA_H
#define CC2530DIS_DA_H

#include <vector>
#include "Istr.h"

class DA : public Istr {
public:
    DA(std::vector<uint8_t>::iterator &istr, uint32_t pos) : Istr(pos) {
        bytes.push_back(*istr);
        istr++;
        toString = "DA      A";
    }


};


#endif //CC2530DIS_DA_H
