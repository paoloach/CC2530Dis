//
// Created by paolo on 24/03/18.
//

#ifndef CC2530DIS_LOGIC_BIT_H
#define CC2530DIS_LOGIC_BIT_H

#include <vector>
#include <sstream>
#include "Istr.h"


class Logic_Bit : public Istr {
public:
    Logic_Bit(std::vector<uint8_t>::iterator &istr, uint32_t pos) : Istr(pos) {
        std::stringstream stream;
        bytes.push_back(*istr);
        switch (*istr){
            case 0x82:
                stream << "ANL     C,";
                break;
            case 0xB0:
                stream << "ANL     C,~";
                break;
            case 0x72:
                stream << "ORL     C,";
                break;
            case 0xA0:
                stream << "ORL     C,~";
                break;
        }
        istr++;
        bit = *istr;
        stream <<  std::setfill('0') << std::setw(2) << std::hex << (uint16_t)bit;
        bytes.push_back(*istr);
        istr++;
    }
    uint8_t bit;
};


#endif //CC2530DIS_LOGIC_BIT_H
