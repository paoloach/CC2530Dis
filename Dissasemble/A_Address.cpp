//
// Created by paolo on 22/03/18.
//

#include <iomanip>
#include "A_Address.h"
#include "DirectName.h"


void A_Address::addReg(std::ostream &stream, std::vector<uint8_t>::iterator &istr, std::vector<uint8_t> & bytes) {
    switch (*istr & 0x0F) {
        case 4:
            bytes.push_back(*istr);
            istr++;
            data = *istr;
            stream << "A,#" << std::setfill('0') << std::setw(2) << std::hex << (uint16_t) data;
            break;
        case 5:
            bytes.push_back(*istr);
            istr++;
            data = *istr;
            stream << "A," << DirectName::toString(data);
            break;
        case 6:
        case 7:
            reg = (*istr) & 1;
            stream << "A,@R" << std::to_string(reg);
            break;
        case 8 ... 0x0F:
            reg = (*istr) & 7;
            stream << "A,R" << std::to_string(reg);
            break;
    }
}