//
// Created by paolo on 22/03/18.
//
#include <sstream>
#include <iomanip>
#include "Subb.h"

Subb::Subb(std::vector<uint8_t>::iterator &istr, uint32_t pos) : Istr(pos) {
    std::stringstream stream;

    stream << "SUBB    ";
    addReg(stream, istr, bytes);
    toString = stream.str();
    bytes.push_back(*istr);
    istr++;
}
