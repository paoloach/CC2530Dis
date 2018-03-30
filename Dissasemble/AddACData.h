//
// Created by paolo on 21/03/18.
//

#ifndef CC2530DIS_ADDACDATA_H
#define CC2530DIS_ADDACDATA_H

#include <vector>
#include <sstream>
#include <iomanip>
#include "Istr.h"

class AddACData : public Istr {
public:
    AddACData(std::vector<uint8_t>::iterator &istr, uint32_t pos) : Istr(pos) {
        bytes.push_back(*istr);
        istr++;
        data = *istr;
        bytes.push_back(*istr);
        istr++;
        std::stringstream stream;
        stream << "ADDC    A,#" << std::setfill('0') << std::setw(2) << std::hex << (uint16_t) data;
        toString = stream.str();
    }

    uint8_t data;

};


#endif //CC2530DIS_ADDACDATA_H
