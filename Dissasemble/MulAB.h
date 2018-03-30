//
// Created by paolo on 22/03/18.
//

#ifndef CC2530DIS_MULAB_H
#define CC2530DIS_MULAB_H

#include <vector>
#include "Istr.h"

class MulAB : public Istr {
public:
    MulAB(std::vector<uint8_t>::iterator &istr, uint32_t pos) : Istr(pos) {
        bytes.push_back(*istr);
        istr++;
        toString = "MUL      A,B";
    }

};


#endif //CC2530DIS_MULAB_H
