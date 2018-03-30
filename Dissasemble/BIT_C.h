//
// Created by paolo on 24/03/18.
//



#ifndef CC2530DIS_BIT_C_H
#define CC2530DIS_BIT_C_H

#include <vector>
#include <sstream>
#include "Istr.h"

class BIT_C : public Istr {
public:
    BIT_C(std::vector<uint8_t>::iterator &istr, uint32_t pos) : Istr(pos) {
        std::stringstream stream;
        bytes.push_back(*istr);
        uint8_t code = *istr & 0xF0;
        bool carry = *istr & 1;
        switch (code) {
            case 0xC0:
                stream << "CRL ";
                break;
            case 0xD0:
                stream << "SETB";
                break;
            case 0xB0:
                stream << "CPL ";
                break;
        }
        istr++;
        if (carry)
            stream << "    C";
        else {
            bit = *istr;
            bytes.push_back(*istr);
            istr++;
            stream << "    " << DirectName::bitToString(bit);
        }
        toString = stream.str();
    }

    uint8_t bit;
};


#endif //CC2530DIS_BIT_C_H
