//
// Created by paolo on 20/03/18.
//

#include <fstream>
#include <iostream>
#include "MapLoader.h"
#include <boost/algorithm/string.hpp>
#include "Code.h"

FlashMap MapLoader::load(std::string file) {
    int custom_segment_part = 10000;
    int lineCounter = 0;
    FlashMap result;
    std::ifstream mapFile(file);
    std::string line;
    while (std::getline(mapFile, line)) {
        lineCounter++;
        boost::trim(line);
        if (line.compare(0, 7, "<CODE_C") == 0) {
            Code code(mapFile);
            if (result.findFunction(code.getName()) != nullptr) {
                code.segmentPart = custom_segment_part;
                custom_segment_part++;
            }
            result.functions.push_back(code);
        }
        if (line.compare(0, 12, "<BANKED_CODE") == 0) {
            Code code(mapFile);
            if (result.findFunction(code.getName()) != nullptr) {
                code.segmentPart = custom_segment_part;
                custom_segment_part++;
            }
            result.functions.push_back(code);
        }

        if (line.compare(0, 7, "XDATA_Z") == 0) {
            XData xData(mapFile);
            result.xData.push_back(xData);
        }
        if (line.find("SEGMENTS IN ADDRESS ORDER") != std::string::npos) {
            break;
        }
    }
    std::sort(result.functions.begin(), result.functions.end(), [](Code a, Code b) { return a.start < b.start; });
    std::sort(result.xData.begin(), result.xData.end(), [](XData a, XData b) { return a.start < b.start; });
    return result;
}
