//
// Created by paolo on 22/03/18.
//

#ifndef CC2530DIS_SUBB_H
#define CC2530DIS_SUBB_H
#include <vector>
#include "Istr.h"
#include "A_Address.h"

class Subb  : public Istr, public A_Address{
public:
    Subb(std::vector<uint8_t>::iterator & istr, uint32_t pos);
    uint8_t  data;
    uint8_t reg;
};


#endif //CC2530DIS_SUBB_H
