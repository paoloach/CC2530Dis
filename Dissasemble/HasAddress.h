//
// Created by paolo on 24/03/18.
//

#ifndef CC2530DIS_HASADDRESS_H
#define CC2530DIS_HASADDRESS_H


#include <cstdint>
#include "Istr.h"

class HasAddress : public Istr {
public:
    HasAddress(uint32_t pos): Istr(pos){}
    uint16_t addr;

    virtual bool isAddressable() const {return true;}
};


#endif //CC2530DIS_HASADDRESS_H
