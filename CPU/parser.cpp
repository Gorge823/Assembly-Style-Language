#include "parser.h"
#include <queue>
#include <string>
#include <sstream>

void parser::parseInstruction(std::string instruction) {

    for (int i = 0; i < instruction.length(); i++) {
        if (instruction[i] == ',')
            instruction[i] = ' ';
    }

    std::istringstream iss(instruction);
    std::string arg;

    while (iss >> arg) {

        instructionQueue.push(arg);
    }

    return;
}