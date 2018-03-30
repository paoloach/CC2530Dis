//
// Created by paolo on 23/03/18.
//

#ifndef CC2530DIS_MOV_RN_A_H
#define CC2530DIS_MOV_RN_A_H

#include <vector>
#include <sstream>
#include "Istr.h"

class MOV_Rn_A : public Istr {
public:
    MOV_Rn_A(std::vector<uint8_t>::iterator &istr, uint32_t pos) : Istr(pos) {
        reg = (*istr) & 0x07;
        bytes.push_back(*istr);
        istr++;
        std::stringstream stream;
        stream << "MOV     R" << (uint16_t) reg << ",A";
        toString = stream.str();
    }

    uint8_t reg;
};


#endif //CC2530DIS_MOV_RN_A_H
