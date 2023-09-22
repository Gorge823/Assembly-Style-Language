#pragma once

#include <iostream>
#include <queue>
#include <string>
#include <sstream>

extern std::queue<std::string> instructionQueue;

class parser {
public:
	void parseInstruction(std::string instruction);
};