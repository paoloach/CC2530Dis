//
// Created by paolo on 21/03/18.
//

#ifndef CC2530DIS_ADDACINDIRECT_H
#define CC2530DIS_ADDACINDIRECT_H

#include <vector>
#include <iomanip>
#include "Istr.h"

class AddACIndirect : public Istr {
public:
    AddACIndirect(std::vector<uint8_t>::iterator &istr, uint32_t pos) : Istr(pos) {
        reg = (*istr) & 1;
        bytes.push_back(*istr);
        istr++;
        toString = "ADDC    A,@R" + std::to_string(reg);
    }

    uint8_t reg;

};


#endif //CC2530DIS_ADDACINDIRECT_H
