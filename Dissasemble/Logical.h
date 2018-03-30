//
// Created by paolo on 22/03/18.
//

#ifndef CC2530DIS_LOGICAL_H
#define CC2530DIS_LOGICAL_H


#include <vector>
#include <ostream>
#include "Istr.h"

class Logical : public Istr {
public:
    Logical(std::vector<uint8_t>::iterator &istr, uint32_t pos, std::string prefix) : Istr(pos) {
        std::stringstream stream;

        stream << prefix;
        addReg(stream, istr);
        toString = stream.str();
        bytes.push_back(*istr);
        istr++;
    }

    void addReg(std::ostream &ostream, std::vector<uint8_t>::iterator &istr);

    uint8_t data;
    uint8_t direct;
    uint8_t reg;
};


#endif //CC2530DIS_LOGICAL_H
