#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>

extern std::vector<std::string> code;
extern std::unordered_map<std::string, int> jmpLabels;

class fileParser {
public:
	bool parseFile();
};