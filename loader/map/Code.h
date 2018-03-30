//
// Created by paolo on 20/03/18.
//

#ifndef CC2530DIS_CODE_H
#define CC2530DIS_CODE_H

#include <string>
#include <istream>
#include <ostream>

class Code {
public:
    Code(std::istream & mapFile );

    std::string name;
    uint32_t  start;
    uint32_t  end;
    uint32_t segmentPart;

    std::string getName() const {return (name.empty() ? ("segment " + std::to_string(segmentPart)):  name);}

    friend std::ostream  & operator <<(std::ostream & out, const Code & code);
};


#endif //CC2530DIS_CODE_H
