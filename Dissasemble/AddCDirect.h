//
// Created by paolo on 21/03/18.
//

#ifndef CC2530DIS_ADDCDIRECT_H
#define CC2530DIS_ADDCDIRECT_H

#include <vector>
#include <sstream>
#include <iomanip>
#include "Istr.h"
#include "DirectName.h"

class AddCDirect : public Istr {
public:
    AddCDirect(std::vector<uint8_t>::iterator &istr, uint32_t pos) : Istr(pos) {
        bytes.push_back(*istr);
        istr++;
        direct = *istr;
        bytes.push_back(*istr);
        istr++;
        std::stringstream stream;
        stream << "ADDC     A," << DirectName::toString(direct);
        toString = stream.str();
    }

    uint8_t direct;

};


#endif //CC2530DIS_ADDCDIRECT_H
