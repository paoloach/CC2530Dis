//
// Created by paolo on 21/03/18.
//

#ifndef CC2530DIS_DISSASEMBLE_H
#define CC2530DIS_DISSASEMBLE_H

#include <map>
#include "Function.h"
#include "../loader/map/FlashMap.h"


using FunctionsDone = std::map<std::string, std::unique_ptr<Function>> ;

class Dissasemble {
public:
    static std::unique_ptr<Function> dissasemble(std::vector<uint8_t> & memory, FlashMap & flashMap, Code * code, FunctionsDone & functionDone);
};


#endif //CC2530DIS_DISSASEMBLE_H
