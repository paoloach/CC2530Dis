//
// Created by paolo on 22/03/18.
//

#include <sstream>
#include <iostream>
#include "R_A.h"

R_A::R_A(std::vector<uint8_t>::iterator &istr, uint32_t pos) : Istr(pos) {
    left = *istr & 0x20;
    carry = *istr & 0x10;
    std::stringstream stream;

    stream << "R" << (left ? 'L' : 'R') << (carry ? 'C' : ' ') << std::string("     A");
    toString = stream.str();
    bytes.push_back(*istr);
    istr++;
}
