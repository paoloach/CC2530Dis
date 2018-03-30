//
// Created by paolo on 22/03/18.
//
#include <iomanip>
#include "Logical.h"

void Logical::addReg(std::ostream &stream, std::vector<uint8_t>::iterator &istr) {
    uint8_t  code = *istr & 0x0F;
    bytes.push_back(*istr);
    switch (code) {
        case 2:
            istr++;
            data = *istr;
            stream << std::setfill('0') << std::setw(2) << std::hex << (uint16_t) data << ",A";
            break;
        case 3:
            istr++;
            direct = *istr;
            bytes.push_back(*istr);
            istr++;
            data = *istr;
            stream << std::setfill('0') << std::setw(2) << std::hex << (uint16_t) direct << ",#" << (uint16_t )data;
            break;
        case 4:
            istr++;
            data = *istr;
            stream << "A,#" << std::setfill('0') << std::setw(2) << std::hex << (uint16_t) data;
            break;
        case 5:
            istr++;
            direct = *istr;
            stream << "A," << std::setfill('0') << std::setw(2) << std::hex << (uint16_t) direct;
            break;
        case 6:
        case 7:
            reg = code & 1;
            stream << "A,@R" + std::to_string(reg);
            break;
        case 0x08 ... 0x0F:
            reg = code & 0x07;
            stream << "A,R" + std::to_string(reg);
            break;
    }
}
