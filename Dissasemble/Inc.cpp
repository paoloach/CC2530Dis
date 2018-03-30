//
// Created by paolo on 22/03/18.
//
#include <sstream>
#include <iomanip>
#include "Inc.h"

Inc::Inc(std::vector<uint8_t>::iterator &istr, uint32_t pos) : Istr(pos) {
    std::stringstream stream;

    stream << "INC     ";
    if (*istr == 0xA3){
        bytes.push_back(*istr);
        stream << "DPTR";
    } else {
        addReg(stream, istr, bytes);
    }
    toString = stream.str();
    istr++;
}
