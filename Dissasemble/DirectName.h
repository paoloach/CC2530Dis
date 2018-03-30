//
// Created by paolo on 23/03/18.
//

#ifndef CC2530DIS_DIRECTNAME_H
#define CC2530DIS_DIRECTNAME_H

#include <string>
#include <cstdint>

class DirectName {
public:
    static std::string toString(uint8_t value);
    static std::string bitToString(uint8_t value);
};


#endif //CC2530DIS_DIRECTNAME_H
