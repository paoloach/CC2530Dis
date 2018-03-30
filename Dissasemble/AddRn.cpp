//
// Created by paolo on 21/03/18.
//

#include "AddRn.h"

AddRn::AddRn(std::vector<uint8_t>::iterator &istr, uint32_t pos) : Istr(pos), code(*istr) {
    reg = code & 0x07;
    toString = "ADD     A,R" + std::to_string(reg);
    bytes.push_back(*istr);
    istr++;
}
