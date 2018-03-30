//
// Created by paolo on 20/03/18.
//
#include <boost/algorithm/string.hpp>
#include <iomanip>
#include <iostream>
#include <ctype.h>
#include "Code.h"

Code::Code(std::istream &mapFile) {
    std::string line;
    while (true) {
        std::getline(mapFile, line);
        if (line.find("    ------------------") != std::string::npos)
            break;
        if (line.find("    *******************") != std::string::npos)
            break;

        int code = line.find("CODE");
        if (code != std::string::npos) {
            start = stoi(line.substr(code + 5, 8), nullptr, 16);
            if (line[code+13] == ' ')
                end = stoi(line.substr(code + 16, 8), nullptr, 16);
            else
                end = start;
        }
        int segmentFound = line.find("Segment part");
        if (segmentFound == 2){
            segmentPart = stoi(line.substr(segmentFound+13));
        }
        int entryFound = line.find("ENTRY");
        if (entryFound != std::string::npos){
            std::getline(mapFile, line);
            std::getline(mapFile, line);
            if (line[entryFound] != ' ')
                for(auto iter = line.begin()+entryFound; iter  != line.end() && !isspace(*iter); iter++)
                    name += *iter;
        }
        int localFound = line.find("LOCAL");
        if (localFound != std::string::npos){
            std::getline(mapFile, line);
            std::getline(mapFile, line);
            if (line[localFound] != ' ')
                for(auto iter = line.begin()+localFound; iter  != line.end() && !isspace(*iter); iter++)
                    name += *iter;
        }
    }

}


std::ostream  & operator <<(std::ostream & out, const Code & code) {
    if (code.name.empty()){
        out << "segment part " << code.segmentPart;
    } else {
        out << "function: " << code.name;
    }
    out <<  " [" << std::hex << code.start << ":" << code.end << "]" << std::dec;
    return out;
}