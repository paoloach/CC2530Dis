//
// Created by paolo on 22/03/18.
//

#ifndef CC2530DIS_R_A_H
#define CC2530DIS_R_A_H

#include <vector>
#include "Istr.h"

class R_A : public  Istr{
public:
    R_A(std::vector<uint8_t>::iterator &istr, uint32_t pos);
    bool left;
    bool carry;
};


#endif //CC2530DIS_R_A_H
