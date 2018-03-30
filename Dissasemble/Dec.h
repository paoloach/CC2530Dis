//
// Created by paolo on 22/03/18.
//

#ifndef CC2530DIS_DEC_H
#define CC2530DIS_DEC_H
#include <vector>
#include "Istr.h"
#include "IncDecReg.h"

class Dec : public Istr, public IncDecReg {
public:
    Dec(std::vector<uint8_t>::iterator &istr, uint32_t pos);

};


#endif //CC2530DIS_DEC_H
