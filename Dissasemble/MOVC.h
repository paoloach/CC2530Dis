//
// Created by paolo on 23/03/18.
//

#ifndef CC2530DIS_MOVC_H
#define CC2530DIS_MOVC_H

#include <vector>
#include <sstream>
#include <iostream>
#include "Istr.h"

class MOVC : public Istr {
public:
    MOVC(std::vector<uint8_t>::iterator &istr, uint32_t pos) : Istr(pos) {
        dptr = (*istr) & 0x10;
        bytes.push_back(*istr);
        istr++;
        std::stringstream stream;
        stream << "MOVC    A,@A +" << (dptr ? "DPTR" : "PC");
        toString = stream.str();
    }

    bool dptr;
    uint8_t data;
};


#endif //CC2530DIS_MOVC_H
