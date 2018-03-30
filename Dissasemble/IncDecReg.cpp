//
// Created by paolo on 22/03/18.
//

#include <iomanip>
#include "IncDecReg.h"
#include "DirectName.h"

void IncDecReg::addReg(std::ostream &stream, std::vector<uint8_t>::iterator &istr, std::vector<uint8_t>  &bytes) {
    bytes.push_back(*istr);
    switch (*istr & 0x0F) {
        case 4:
            stream << "A";
            break;
        case 5:
            istr++;
            data = *istr;
            bytes.push_back(*istr);
            stream <<  DirectName::toString(data);
            istr++;
            break;
        case 6:
        case 7:
            reg = *istr & 1;
            stream << "@R" + std::to_string(reg);
            break;
        case 8 ... 0x0F:
            reg = *istr & 0x07;
            stream << "R" + std::to_string(reg);
            break;
    }
}
