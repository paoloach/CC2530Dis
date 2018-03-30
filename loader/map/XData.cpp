//
// Created by paolo on 20/03/18.
//
#include <boost/algorithm/string.hpp>
#include <iomanip>
#include <iostream>
#include "XData.h"

XData::XData(std::istream &mapFile) {
    std::string line;
    while (true) {
        std::getline(mapFile, line);
        if (line.find("    ------------------") != std::string::npos)
            break;
        if (line.find("    *******************") != std::string::npos)
            break;

        int code = line.find("XDATA ");
        if (code != std::string::npos) {
            start = stoi(line.substr(code + 6, 8), nullptr, 16);
            if (line[code+13] == ' ')
                end = stoi(line.substr(code + 17, 8), nullptr, 16);
            else
                end = start;
        }
        int segmentFound = line.find("Segment part");
        if (segmentFound != std::string::npos){
            segmentPart = stoi(line.substr(segmentFound+13));
        }
        int entryFound = line.find("ENTRY");
        if (entryFound != std::string::npos){
            std::getline(mapFile, line);
            std::getline(mapFile, line);
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



std::ostream  & operator <<(std::ostream & out, const XData & xData) {
    if (xData.name.empty()){
        out << "segment part " << xData.segmentPart;
    } else {
        out << "variable: " << xData.name;
    }
    out <<  " [" << std::hex << xData.start << ":" << xData.end << "]";
    return out;
}
