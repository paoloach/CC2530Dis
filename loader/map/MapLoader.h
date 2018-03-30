//
// Created by paolo on 20/03/18.
//

#ifndef CC2530DIS_MAPLOADER_H
#define CC2530DIS_MAPLOADER_H

#include <string>
#include "FlashMap.h"

class MapLoader {
public:
    static FlashMap load(std::string  file);
};


#endif //CC2530DIS_MAPLOADER_H
