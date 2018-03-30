//
// Created by paolo on 21/03/18.
//

#ifndef CC2530DIS_ADDISTR_H
#define CC2530DIS_ADDISTR_H


#include <vector>
#include "Istr.h"

class AddRn : public Istr{
public:
    AddRn(std::vector<uint8_t>::iterator & istr, uint32_t pos);
    uint8_t  code;
    uint8_t  reg;
};


#endif //CC2530DIS_ADDISTR_H
