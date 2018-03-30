//
// Created by paolo on 20/03/18.
//

#ifndef CC2530DIS_XDATA_H
#define CC2530DIS_XDATA_H

#include <string>
class XData {
public:
    XData(std::istream & mapFile );

    std::string name;
    uint32_t  start;
    uint32_t  end;
    uint32_t  segmentPart;

    friend std::ostream  & operator <<(std::ostream & out, const XData & code);
};


#endif //CC2530DIS_XDATA_H
