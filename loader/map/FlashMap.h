//
// Created by paolo on 20/03/18.
//

#ifndef CC2530DIS_FLASHMAP_H
#define CC2530DIS_FLASHMAP_H

#include <vector>
#include "Code.h"
#include "XData.h"


class FlashMap {
public:
    FlashMap() = default;

    FlashMap(FlashMap &&other) : functions(std::move(other.functions)), xData(std::move(other.xData)) {}

    std::vector<Code> functions;
    std::vector<XData> xData;

    Code *findFunction(const std::string name);
    Code *findFunction(uint16_t addr);
};


#endif //CC2530DIS_FLASHMAP_H
