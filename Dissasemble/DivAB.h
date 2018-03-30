//
// Created by paolo on 22/03/18.
//

#ifndef CC2530DIS_DIVAB_H
#define CC2530DIS_DIVAB_H

#include <vector>
#include "Istr.h"

class DivAB  : public Istr{
public:
    DivAB(std::vector<uint8_t>::iterator & istr, uint32_t pos) :Istr(pos){
            istr++;
            toString = "DIV      A";
    }

};


#endif //CC2530DIS_DIVAB_H
