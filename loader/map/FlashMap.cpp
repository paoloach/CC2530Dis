//
// Created by paolo on 20/03/18.
//

#include <iostream>
#include "FlashMap.h"

Code * FlashMap::findFunction(const std::string functionName) {
    for(auto & code: functions){
        if (code.getName() == functionName)
            return &code;
    }
    return nullptr;
}

Code *FlashMap::findFunction(uint16_t addr) {
    if (addr == 0x49D5){
        std::cout << "ciao" << std::endl;
    }
    for(auto & code: functions){
        if (code.start >= addr && addr <= code.end)
            return &code;
    }
    return nullptr;
}
