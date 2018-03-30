//
// Created by paolo on 21/03/18.
//

#ifndef CC2530DIS_ADDAINDIRECT_H
#define CC2530DIS_ADDAINDIRECT_H

#include <vector>
#include <iomanip>
#include "Istr.h"

class AddAIndirect : public Istr {
public:
    AddAIndirect(std::vector<uint8_t>::iterator &istr, uint32_t pos) : Istr(pos) {
        reg = (*istr) & 1;
        bytes.push_back(*istr);
        istr++;
        toString = "ADD     A,@R" + std::to_string(reg);
    }

    uint8_t reg;
};

#endif //CC2530DIS_ADDAINDIRECT_H
