//
// Created by paolo on 24/03/18.
//

#ifndef CC2530DIS_DJNZ_H
#define CC2530DIS_DJNZ_H

#include <vector>
#include "Istr.h"
#include "DirectName.h"

class DJNZ : public Istr{
public:
    DJNZ(std::vector<uint8_t>::iterator & istr, uint32_t pos):Istr(pos){
        std::stringstream stream;

        stream << "DJNZ    ";
        switch (*istr & 0x0F) {
            case 5:
                bytes.push_back(*istr);
                istr++;
                data = *istr;
                stream  << DirectName::toString(data);
                pos++;
                break;
            case 8 ... 0x0F:
                reg = (*istr) & 7;
                stream << "R" << std::to_string(reg);
                break;
        }
        bytes.push_back(*istr);
        istr++;
        addr = 2 + pos +*(std::vector<int8_t>::iterator &) istr;
        bytes.push_back(*istr);
        istr++;
        stream << "," << std::setfill('0') << std::setw(4) << std::hex << (uint16_t) addr;
        toString = stream.str();
    }
    uint8_t  addr;
    uint8_t  reg;
    uint8_t  data;
};


#endif //CC2530DIS_DJNZ_H
