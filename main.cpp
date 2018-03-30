#include <boost/program_options.hpp>
#include <iostream>
#include <fstream>
#include "loader/intel-hex/IntelHexLoader.h"
#include "loader/map/MapLoader.h"
#include "Dissasemble/Dissasemble.h"

using namespace boost::program_options;

static constexpr auto HEX_FILE = "file";
static constexpr auto MAP_FILE = "map";
static constexpr auto FUNCTION_NAME = "function";
static constexpr auto HELP = "help";

variables_map getVariableMap(size_t argc, char const *argv[]);

int main(int argc, char const *argv[]) {
    auto options = getVariableMap(argc, argv);
    std::vector<uint8_t> memory;

    std::cout << "intel hex file: " << options[HEX_FILE].as<std::string>() << std::endl;
    std::cout << "map file: " << options[MAP_FILE].as<std::string>() << std::endl;

    std::ifstream hexFile(options[HEX_FILE].as<std::string>());

    auto flashMap = MapLoader::load(options[MAP_FILE].as<std::string>());
    if (options.count(FUNCTION_NAME) == 0) {
        for (auto &code: flashMap.functions)
            std::cout << code << std::endl;
        exit(0);
    }

    std::string functionName = options[FUNCTION_NAME].as<std::string>();
    Code * code = flashMap.findFunction(functionName);

    if (code == nullptr){
        for (auto &code: flashMap.functions)
            std::cout << code << std::endl;
        exit(0);
    }


    for (auto &code: flashMap.functions)
        std::cout << code << std::endl;

    IntelHexLoader::load(hexFile, memory);
    FunctionsDone functionDone;

    auto function = Dissasemble::dissasemble(memory, flashMap, code, functionDone);
    functionDone[function->name] =std::move(function);
    std::vector<Function *> functions;


    for (auto &child: functionDone) {
        functions.push_back(child.second.get());
    }
    std::sort(std::begin(functions), std::end(functions), [](Function * a, Function * b){return a->start < b->start;});
    std::cout << "Functions: " << std::endl;
    for(auto function: functions){
        std::cout << function->name<< std::endl;
        for (auto &istr: function->instrs) {
            std::cout << istr.get() << std::endl;
        }
    }

    return 0;
}

variables_map getVariableMap(size_t argc, char const *argv[]) {
    options_description desc("Allowed options");
    desc.add_options()
            (HELP, "help")
            (MAP_FILE, value<std::string>(), "map file")
            (FUNCTION_NAME, value<std::string>(), "function to decode")
            (HEX_FILE, value<std::string>(), "hex intel file");

    variables_map vm{};
    store(parse_command_line(argc, argv, desc), vm);
    notify(vm);
    if (vm.count(HELP)) {
        std::cout << desc << std::endl;
        exit(1);
    }
    return vm;
}