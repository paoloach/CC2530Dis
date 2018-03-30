//
// Created by paolo on 21/03/18.
//

#ifndef CC2530DIS_ADDCRN_H
#define CC2530DIS_ADDCRN_H

#include <vector>
#include "Istr.h"


class AddCRn : public Istr {
public:
    AddCRn(std::vector<uint8_t>::iterator &istr, uint32_t pos) : Istr(pos) {
        reg = (*istr) & 0x07;
        bytes.push_back(*istr);
        istr++;
        toString = "ADDC    A,R" + std::to_string(reg);
    }

    uint8_t reg;

};


#endif //CC2530DIS_ADDCRN_H
