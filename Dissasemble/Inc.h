//
// Created by paolo on 22/03/18.
//

#ifndef CC2530DIS_INC_H
#define CC2530DIS_INC_H

#include <vector>
#include "Istr.h"
#include "IncDecReg.h"

class Inc : public Istr, public IncDecReg {
public:
    Inc(std::vector<uint8_t>::iterator &istr, uint32_t pos);
};


#endif //CC2530DIS_INC_H
