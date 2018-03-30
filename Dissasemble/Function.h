//
// Created by paolo on 21/03/18.
//

#ifndef CC2530DIS_FUNCTION_H
#define CC2530DIS_FUNCTION_H

#include <string>
#include <vector>
#include <set>
#include <memory>
#include "Istr.h"

class Function {
public:
    Function(std::string && name, int start, int end):name(name), start(start), end(end){}
    std::string name;
    int start;
    int end;
    std::vector<std::unique_ptr<Istr>> instrs;
    std::set<Function *> called;
};


#endif //CC2530DIS_FUNCTION_H
