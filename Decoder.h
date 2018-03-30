//
// Created by paolo on 20/03/18.
//

#ifndef CC2530DIS_DECODER_H
#define CC2530DIS_DECODER_H

#include <vector>
#include <cstdint>


class Decoder {
public:
    void decode(std::vector<uint8_t> && memory);
};


#endif //CC2530DIS_DECODER_H
