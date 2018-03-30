//
// Created by paolo on 22/03/18.
//

#ifndef CC2530DIS_MOV_A_H
#define CC2530DIS_MOV_A_H

#include <vector>
#include "Istr.h"
#include "A_Address.h"

class MOV_A : public Istr, public A_Address {
public:
    MOV_A(std::vector<uint8_t>::iterator &istr, uint32_t pos);

    uint8_t data;
    uint8_t reg;

};


#endif //CC2530DIS_MOV_A_H
