//
// Created by paolo on 22/03/18.
//

#include "MOV_A.h"

MOV_A::MOV_A(std::vector<uint8_t>::iterator &istr, uint32_t pos) :Istr(pos){
    std::stringstream stream;
    stream << "MOV     ";
    addReg(stream, istr, bytes);
    toString = stream.str();
    bytes.push_back(*istr);
    istr++;
}
