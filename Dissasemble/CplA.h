//
// Created by paolo on 22/03/18.
//

#ifndef CC2530DIS_CPLA_H
#define CC2530DIS_CPLA_H

#include <vector>
#include "Istr.h"

class CplA : public Istr {
public:
    CplA(std::vector<uint8_t>::iterator &istr, uint32_t pos) : Istr(pos) {
        bytes.push_back(*istr);
        istr++;
        toString = "CPL     A";
    }


};


#endif //CC2530DIS_CPLA_H
