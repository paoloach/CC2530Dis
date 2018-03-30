//
// Created by paolo on 23/03/18.
//

#ifndef CC2530DIS_XCH_H
#define CC2530DIS_XCH_H

#include <vector>
#include <sstream>
#include "Istr.h"
#include "A_Address.h"

class XCH : public Istr, public A_Address {
public:
    XCH(std::vector<uint8_t>::iterator &istr, uint32_t pos) : Istr(pos) {
        std::stringstream stream;

        stream << "XCH     ";
        addReg(stream, istr, bytes);
        toString = stream.str();
        bytes.push_back(*istr);
        istr++;
    }
};


#endif //CC2530DIS_XCH_H
