//
// Created by paolo on 22/03/18.
//

#include "Dec.h"

Dec::Dec(std::vector<uint8_t>::iterator &istr, uint32_t pos) : Istr(pos) {
    std::stringstream stream;
    bytes.push_back(*istr);
    stream << "DEC     ";
    addReg(stream, istr, bytes);
    toString = stream.str();
    istr++;

}
