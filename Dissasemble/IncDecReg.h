//
// Created by paolo on 22/03/18.
//

#ifndef CC2530DIS_INCDECREG_H
#define CC2530DIS_INCDECREG_H

#include <vector>
#include <ostream>

class IncDecReg {
protected:
    void addReg(std::ostream & ostream, std::vector<uint8_t>::iterator &istr, std::vector<uint8_t>  &bytes);

    uint8_t data;
    uint8_t reg;
};


#endif //CC2530DIS_INCDECREG_H
