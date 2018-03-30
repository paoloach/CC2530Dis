//
// Created by paolo on 24/03/18.
//

#ifndef CC2530DIS_JCOND_H
#define CC2530DIS_JCOND_H

#include <vector>
#include <sstream>
#include "Istr.h"

class JCOND : public Istr {
public:
    JCOND(std::vector<uint8_t>::iterator &istr, uint32_t pos) : Istr(pos) {
        uint8_t code = *istr & 0x70;
        bytes.push_back(*istr);
        istr++;
        if (code == 0x10 || code == 0x20 || code == 0x30){
            bit = *istr;
            bytes.push_back(*istr);
            istr++;
        }
        addr = pos  +2+ *(std::vector<int8_t>::iterator &)istr;
        std::stringstream stream;
        stream << 'J';
        switch (code) {
            case 0x10:
                stream << "BC     " << DirectName::bitToString (bit) << ",";
                break;
            case 0x20:
                stream << "B      " << DirectName::bitToString (bit) << ",";
                break;
            case 0x30:
                stream << "NB     " << DirectName::bitToString (bit) << ",";
                break;
            case 0x40:
                stream << "C      ";
                break;
            case 0x50:
                stream << "NC     ";
                break;
            case 0x60:
                stream << "Z      ";
                break;
            case 0x70:
                stream << "NZ     ";
                break;
        }
        bytes.push_back(*istr);
        istr++;
        stream << std::setfill('0') << std::setw(4) << std::hex << (uint16_t) addr;
        toString = stream.str();
    }
    uint16_t  addr;
    uint8_t bit;
};


#endif //CC2530DIS_JCOND_H
