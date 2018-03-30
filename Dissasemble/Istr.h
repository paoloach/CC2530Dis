//
// Created by paolo on 21/03/18.
//

#ifndef CC2530DIS_ISTR_H
#define CC2530DIS_ISTR_H

#include <ostream>
#include <iomanip>
#include <vector>

class Istr {
public:
    Istr(uint32_t pos):pos(pos){}
    std::string toString;
    uint32_t pos;
    std::vector<uint8_t> bytes;

    friend std::ostream & operator<<(std::ostream & out, const Istr * istr){
        out << std::setfill ('0') << std::setw(5)<<  std::hex << istr->pos << "  ";
        for (uint8_t value: istr->bytes){
            out << std::setw(2) << (uint16_t )value << " ";
        }
        for (int i=0; i < 15-istr->bytes.size()*3; i++)
            out << ' ';
        out << istr->toString;
    }

    virtual bool isAddressable() const {return false;}
};


#endif //CC2530DIS_ISTR_H
